#include "RequestHandler.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/filesystem.hpp>
#include <fstream>
#include <fstream>
#include <iostream>
#include <locale>
#include <memory>
#include <sstream>
#include <sys/sendfile.h>
#include <vector>

#define pull(ofd, ifd, offset, length) sendfile((ofd), (ifd), &(offset), (length))

using namespace boost::filesystem;
using namespace std;

RequestHandler::RequestHandler(std::shared_ptr<boost::asio::ip::tcp::socket>&& socket)
    : m_socket(socket)
{
}

void RequestHandler::run()
{
    boost::asio::spawn(m_socket->get_io_service(), boost::bind(&RequestHandler::handle, shared_from_this(), _1));
}

void RequestHandler::handle(boost::asio::yield_context yield) try {
    bool keepalive = true;
    string headers(baseHeaders());
    string method, url, protocol = "HTTP/1.1";
    int code;
    int file;

    while (keepalive) {
        boost::asio::streambuf buffer(1024);
        code = 404;
        boost::asio::async_read_until(*m_socket, buffer, "\r\n\r\n", yield);
        string request = boost::asio::buffer_cast<const char*>(buffer.data());
        do {
            istringstream iss(request);
            iss >> method >> url >> protocol;
            url = decodeUrl(url);
            url = removeGet(url);
            size_t first_mark_pos = url.find_first_of("?");
            if (first_mark_pos != string::npos) {
                url = url.substr(0, first_mark_pos);
            }

            if (url.empty()) {
                cerr << "wrong url\n";
                break;
            }
            if (!isFile(url)) {
                cerr << "wrong url file\n";
                break;
            }
            if ((file = open(url.c_str(), O_RDONLY)) == -1) {
                cerr << "can't  open file\n";
                break;
            }

            code = 200;
            keepalive = false;
            headers += getFileHeaders(url);
            headers = createHeaders(protocol, code, headers);

        } while (0);

        if (code != 200) {
            keepalive = false;
            headers = createHeaders(protocol, code, headers);
            std::vector<char> headersVector(headers.c_str(), headers.c_str() + headers.length() + 1);

            boost::asio::async_write(*m_socket, boost::asio::buffer(&headersVector[0], headers.size()), yield);
            const char* errorPage = "<html> there aren't such file </html>";
            boost::asio::async_write(*m_socket, boost::asio::buffer(errorPage, strlen(errorPage)), yield);
        } else {
            std::vector<char> headersVector(headers.c_str(), headers.c_str() + headers.length() + 1);
            boost::asio::async_write(*m_socket, boost::asio::buffer(&headersVector[0], headersVector.size()), yield);

            off_t offset = 0;
            int send = 0;
            path p(url);
            int length = file_size(p);
            m_socket->async_write_some(boost::asio::null_buffers(), yield);
            send = pull(m_socket->native(), file, offset, length);
            if (send < 0) {
                keepalive = false;
                cerr << "sendfile failed";
                break;
            }
        }
        ::close(file);
    }
    RequestHandler::close();
} catch (std::exception& e) {
    cerr << "connection close" << e.what();
}
string RequestHandler::decodeUrl(const std::string& url) const
{
    string res;
    for (size_t i = 0; i < url.length(); ++i) {
        if (url[i] == '%') {
            int val;
            sscanf(url.substr(i + 1, 2).c_str(), "%x", &val);
            res += static_cast<char>(val);
            i += 2;
        } else if (url[i] == '+') {
            res += ' ';
        } else {
            res += url[i];
        }
    }
    return res;
}

bool RequestHandler::isFile(const std::string filename) const
{
    path p(filename);
    return (is_regular_file(p) and exists(p));
}

string RequestHandler::baseHeaders() const
{
    std::ostringstream headers;
    headers.imbue(std::locale(headers.getloc(), new boost::posix_time::time_facet("%a, %d %b %Y %H:%M:%S GMT")));
    headers << "Server: FileServer/1.0 (Linux) \r\n"
            << "Date: " << boost::posix_time::second_clock::universal_time() << "\r\n"
            << "Connection: close\r\n";
    return headers.str();
}

string RequestHandler::createHeaders(const std::string& protocol, int code, const std::string& headers)
{
    stringstream response;
    response << protocol << ' ' << getCode(code) << "\r\n"
             << headers << "\r\n";
    cout << response.str();
    return response.str();
}

string RequestHandler::removeGet(const string& url)
{
    size_t pos = url.find("get");
    if (pos == string::npos)
        return string();
    string result = url.substr(pos + 4); //length("GET") is i3
    return result;
}

string RequestHandler::getCode(int code) const
{
    switch (code) {
    case 200:
        return "200 OK";
    case 403:
        return "403 Forbidden";
    case 404:
        return "404 Not Found";
    case 405:
        return "405 Method Not Allowed";
    case 501:
        return "501 Not Implemented";
    default:
        return "200 OK";
    }
}

void RequestHandler::close()
{
    boost::system::error_code error = boost::asio::error::interrupted;
    for (; m_socket->is_open() && error == boost::asio::error::interrupted;)
        m_socket->close(error);
}

string RequestHandler::getFileHeaders(const std::string& url)
{
    size_t lastDotPos = url.find_last_of(".");
    string extension = url.substr(lastDotPos + 1);
    std::ostringstream headers;
    headers << "Content-Length: " << file_size(url) << "\r\n"
            << "Content-Type: " << mimeTypes[extension] << "\r\n";
    return headers.str();
}
