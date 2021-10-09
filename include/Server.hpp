#pragma once

#include <list>
#include <string>

#include <SFML/Network.hpp>

#include "Client.hpp"

class Server
{
public:
    Server(const unsigned short udpPort);
    ~Server();

    void printMessage(const std::string& message, const sf::IpAddress& senderIp, const unsigned short senderPort);
    void addClient(Client& client);
    void removeClient(Client& disconnectedClient);

    unsigned short getUdpPort() const;
    sf::UdpSocket& getUdpSocket();

private:
    unsigned short m_udpPort;
    sf::UdpSocket  m_udpSocket;
    sf::Packet     m_packet;

    std::list<Client*> m_clients;
};
