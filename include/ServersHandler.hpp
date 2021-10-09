#pragma once

#include <list>

#include <SFML/Network.hpp>

#include "Server.hpp"

class ServersHandler
{
public:
    ServersHandler(sf::SocketSelector& socketSelector, std::list<Server*>& servers);
    ~ServersHandler();

    void handle();

private:
    sf::SocketSelector& m_socketSelector;
    std::list<Server*>& m_servers;

    sf::Packet m_packet;

    void handleMessage(Server& server, const sf::IpAddress& senderIp, const unsigned short senderPort);
};
