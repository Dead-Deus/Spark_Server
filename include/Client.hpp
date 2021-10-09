#pragma once

#include <SFML/Network.hpp>

class Client
{
public:
    Client(sf::TcpSocket& m_tcpSocket);
    ~Client();

    bool operator==(Client& client);

    sf::TcpSocket& getTcpSocket();
    unsigned short getServerUdpPort() const;
    unsigned short getUdpPort() const;

    void setServerUdpPort(unsigned short port);
    void setUdpPort(unsigned short port);

private:
    sf::TcpSocket* m_tcpSocket;
    unsigned short m_serverUdpPort;
    unsigned short m_udpPort;
};
