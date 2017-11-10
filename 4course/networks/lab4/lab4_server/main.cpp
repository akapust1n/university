#include <boost/asio.hpp>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
unsigned short tcp_port = 1234;

int main(int argc, char* argv[])
{
    boost::array<char, 1024> buf;
    size_t file_size = 0;
    try {
        if (argc == 2) {
            tcp_port = atoi(argv[1]);
        }
        std::cout << argv[0] << " listen on port " << tcp_port << std::endl;
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), tcp_port));
        boost::system::error_code error;
        boost::asio::ip::tcp::socket socket(io_service);
        acceptor.accept(socket);
        std::cout << "get client connection." << std::endl;
        boost::asio::streambuf request_buf;
        boost::asio::read_until(socket, request_buf, "\n\n");
        std::cout << "request size:" << request_buf.size() << "\n";
        std::istream request_stream(&request_buf);
        std::string file_path;
        request_stream >> file_path;
        request_stream >> file_size;
        request_stream.read(buf.c_array(), 2);

        std::cout << file_path << " size is " << file_size << std::endl;
        size_t pos = file_path.find_last_of(‘\\’);
        if (pos != std::string::npos)
            file_path = file_path.substr(pos + 1);
        std::ofstream output_file(file_path.c_str(), std::ios_base::binary);
        if (!output_file) {
            std::cout << "failed to open " << file_path << std::endl;
            return __LINE__;
        }

        do {
            request_stream.read(buf.c_array(), (std::streamsize)buf.size());
            std::cout << __FUNCTION__ << " write " << request_stream.gcount() << " bytes.\n";
            output_file.write(buf.c_array(), request_stream.gcount());
        } while (request_stream.gcount() > 0);

        for (;;) {
            size_t len = socket.read_some(boost::asio::buffer(buf), error);
            if (len > 0)
                output_file.write(buf.c_array(), (std::streamsize)len);
            if (output_file.tellp() == (std::fstream::pos_type)(std::streamsize)file_size)
                break; // file was received
            if (error) {
                std::cout << error << std::endl;
                break;
            }
        }
        std::cout << "received " << output_file.tellp() << " bytes.\n";
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
