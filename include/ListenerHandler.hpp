#pragma once

#include <list>

#include <SFML/Network.hpp>

#include "Client.hpp"

class ListenerHandler
{
public:
    ListenerHandler(sf::SocketSelector& socketSelector, sf::TcpListener& tcpListener, std::list<Client*>& clients);
    ~ListenerHandler();

    void handle();

private:
    sf::SocketSelector& m_socketSelector;
    sf::TcpListener&    m_tcpListener;
    std::list<Client*>& m_clients;

    void registerNewClient();
};
