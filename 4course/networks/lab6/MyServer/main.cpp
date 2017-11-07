#include "MyServer.h"
#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>

int main(int argc, char* argv[])
{
    try {
        if (argc != 2) {
            std::cerr << "Usage: ./MyServer <port>\n";
            return 1;
        }
        boost::asio::io_service io_service;

        MyServer server(io_service, std::atoi(argv[1]));

        io_service.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
