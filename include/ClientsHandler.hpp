#pragma once

#include <list>

#include <SFML/Network.hpp>

#include "Server.hpp"
#include "Client.hpp"

class ClientsHandler
{
public:
    ClientsHandler(sf::SocketSelector& socketSelector, std::list<Server*>& servers, std::list<Client*>& clients);
    ~ClientsHandler();

    void handle();

private:
    sf::SocketSelector& m_socketSelector;
    std::list<Server*>& m_servers;
    std::list<Client*>& m_clients;

    sf::Packet m_packet;

    void handleMessage(Client& client);

    void createServer();
    void destroyServer();
    void connectToServer(Client& client);
    void disconnectFromServer(Client& disconnectedClient);

    Server* findServer(unsigned short serverUdpPort);
};
