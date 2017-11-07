#include "MyServer.h"
#include <boost/bind.hpp>
#include <iostream>
#include <memory>
using namespace std;
MyServer::MyServer(boost::asio::io_service& io_service_, short port)
    : m_io_service(io_service_)
    , m_acceptor(io_service_, tcp::endpoint(tcp::v4(), port))
    , m_tcpSocket(io_service_)
{
    acceptLoop();
}

void MyServer::acceptLoop()
{
    std::shared_ptr<tcp::socket> socket(new tcp::socket(m_io_service));
    m_acceptor.async_accept(*socket,
        boost::bind(&MyServer::onAccept, this, socket,
            boost::asio::placeholders::error));
}

void MyServer::onAccept(shared_ptr<tcp::socket> &socket, const boost::system::error_code& err_code)
{
    if (!err_code)
        try {
            make_shared<RequestHandler>(RequestHandler(std::move(socket)))->run();
        } catch (std::exception& e) {
            cerr << "cannot accept: " << e.what() << std::endl;
        }
    acceptLoop();
}
