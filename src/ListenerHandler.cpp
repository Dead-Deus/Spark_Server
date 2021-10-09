#include "ListenerHandler.hpp"

#include <iostream>

ListenerHandler::ListenerHandler(sf::SocketSelector& socketSelector, sf::TcpListener& tcpListener, std::list<Client*>& clients) :
m_socketSelector(socketSelector),
m_tcpListener(tcpListener),
m_clients(clients)
{
}

ListenerHandler::~ListenerHandler()
{
}

void ListenerHandler::handle()
{
    if (m_socketSelector.isReady(m_tcpListener))
    {
        registerNewClient();
    }
}

void ListenerHandler::registerNewClient()
{
    auto&   tcpSocket = *new sf::TcpSocket();
    Client& client    = *new Client(tcpSocket);

    if (m_tcpListener.accept(tcpSocket) == sf::Socket::Done)
    {
        std::cout << "ListenerHandler::registerNewClient()::[ Ip: " << tcpSocket.getRemoteAddress().toString()
                  << " port: " << tcpSocket.getRemotePort() << "]" << std::endl;
        m_clients.push_back(&client);
        m_socketSelector.add(tcpSocket);
    }
    else
    {
        std::cerr << "ListenerHandler::registerNewClient()::[ Error: failed to accept new client! ]" << std::endl;
        delete &client;
    }
}