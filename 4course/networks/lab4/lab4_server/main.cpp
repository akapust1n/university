#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

using boost::asio::ip::tcp;
int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <server-address> <file path>" << std::endl;
        std::cerr << "sample: " << argv[0] << " 127.0.0.1:1234 c:\\tmp\\a.txt" << std::endl;
        return __LINE__;
    }
    try {
        std::string server_ip_or_host = argv[1];
        size_t pos = server_ip_or_host.find(":");
        if (pos == std::string::npos)
            return __LINE__;
        std::string port_string = server_ip_or_host.substr(pos + 1);
        server_ip_or_host = server_ip_or_host.substr(0, pos);
        boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(server_ip_or_host, port_string);
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
        tcp::resolver::iterator end;
        tcp::socket socket(io_service);
        boost::system::error_code error = boost::asio::error::host_not_found;
        while (error && endpoint_iterator != end) {
            socket.close();
            socket.connect(*endpoint_iterator++, error);
        }
        if (error)
            return __LINE__;
        std::cout << "connected to " << argv[1] << std::endl;
        boost::array<char, 1024> buf;
        std::ifstream source_file(argv[2], std::ios_base::binary | std::ios_base::ate);
        if (!source_file) {
            std::cout << "failed to open " << argv[2] << std::endl;
            return __LINE__;
        }
        size_t file_size = source_file.tellg();
        source_file.seekg(0);
        // first send file name and file size to server
        boost::asio::streambuf request;
        std::ostream request_stream(&request);
        request_stream << argv[2] << "\n"
                       << file_size << "\n\n";
        boost::asio::write(socket, request);
        std::cout << "start sending file content.\n";
        for (;;) {

            if (source_file.eof() == false) {
                source_file.read(buf.c_array(), (std::streamsize)buf.size());
                if (source_file.gcount() <= 0) {
                    std::cout << "read file error " << std::endl;
                    return __LINE__;
                }
                boost::asio::write(socket, boost::asio::buffer(buf.c_array(), source_file.gcount()),
                    boost::asio::transfer_all(), error);
                if (error) {
                    std::cout << "send error:" << error << std::endl;
                    return __LINE__;
                }
            } else
                break;
        }
        std::cout << "send file " << argv[2] << " completed successfully.\n";
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
