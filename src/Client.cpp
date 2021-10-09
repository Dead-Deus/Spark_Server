#include "Client.hpp"

Client::Client(sf::TcpSocket& tcpSocket) : m_tcpSocket(&tcpSocket), m_serverUdpPort(0), m_udpPort(0)
{
}

Client::~Client()
{
    delete m_tcpSocket;
}

bool Client::operator==(Client& client)
{
    return m_tcpSocket->getRemoteAddress() == client.getTcpSocket().getRemoteAddress() &&
           m_tcpSocket->getRemotePort() == client.getTcpSocket().getRemotePort() && m_serverUdpPort == client.getServerUdpPort();
}

sf::TcpSocket& Client::getTcpSocket()
{
    return *m_tcpSocket;
}

unsigned short Client::getServerUdpPort() const
{
    return m_serverUdpPort;
}

unsigned short Client::getUdpPort() const
{
    return m_udpPort;
}

void Client::setServerUdpPort(unsigned short port)
{
    m_serverUdpPort = port;
}

void Client::setUdpPort(unsigned short port)
{
    m_udpPort = port;
}