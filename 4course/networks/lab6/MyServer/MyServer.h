#ifndef MYSERVER_H
#define MYSERVER_H
#include <RequestHandler.h>
#include <boost/asio.hpp>
using namespace boost::asio::ip;
using namespace std;
class MyServer {
public:
    MyServer(boost::asio::io_service& io_service_, short port);

private:
    void acceptLoop();
    void onAccept(shared_ptr<tcp::socket> &socket, const boost::system::error_code& err_code);

private:
    tcp::acceptor m_acceptor;
    tcp::socket m_tcpSocket;
    boost::asio::io_service &m_io_service;
    constexpr static const int m_bufSize = 1024;
};

#endif // MYSERVER_H
