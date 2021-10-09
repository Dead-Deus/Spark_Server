#pragma once

#include <list>

#include <SFML/Network.hpp>

#include "ListenerHandler.hpp"
#include "ServersHandler.hpp"
#include "ClientsHandler.hpp"
#include "Server.hpp"
#include "Client.hpp"

class MainServer
{
public:
    MainServer();
    ~MainServer();

    void run();

private:
    ListenerHandler m_listenerHandler;
    ServersHandler  m_serversHandler;
    ClientsHandler  m_clientsHandler;

    sf::SocketSelector m_socketSelector;
    sf::TcpListener    m_tcpListener;
    sf::Packet         m_packet;

    std::list<Server*> m_servers;
    std::list<Client*> m_clients;

    bool m_isRunning;
};
