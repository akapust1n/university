#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <string>
#include <map>
#include <memory>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/asio/spawn.hpp>


class RequestHandler: public  std::enable_shared_from_this<RequestHandler>
{
public:
    RequestHandler(std::shared_ptr<boost::asio::ip::tcp::socket> &&socket);
    void handle(boost::asio::yield_context yield);
    void run();
private:
    std::string decodeUrl(const std::string &url) const;
    bool isFile(const std::string filename) const;
    std::string baseHeaders() const;
    std::string getFileHeaders(const std::string& url) ;
    std::string createHeaders(const std::string &protocol, int code,const std::string &headers );
    std::string removeGet(const std::string &url);
    std::string getCode(int code) const;
    void close();
private:
    std::map<std::string, std::string>
           mimeTypes = {
               { "txt", "text/plain" },
               { "html", "text/html" },
               { "css", "text/css" },
               { "js", "application/javascript" },
               { "jpg", "image/jpeg" },
               { "jpeg", "image/jpeg" },
               { "png", "image/png" },
               { "gif", "image/gif" },
               { "swf", "application/x-shockwave-flash" },
               { "iso", "application/octet-stream" }
           };
    std::shared_ptr<boost::asio::ip::tcp::socket> m_socket;

};

#endif // REQUESTHANDLER_H
