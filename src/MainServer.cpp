#include "MainServer.hpp"

#include <iostream>
#include <limits>
#include <string>
#include <sstream>

#include "Config.hpp"
#include "Utils.hpp"

MainServer::MainServer() :
m_listenerHandler(m_socketSelector, m_tcpListener, m_clients),
m_serversHandler(m_socketSelector, m_servers),
m_clientsHandler(m_socketSelector, m_servers, m_clients),
m_isRunning(true)
{
    m_tcpListener.listen(cfg::mainServerPort);

    m_socketSelector.add(m_tcpListener);
}

MainServer::~MainServer()
{
    m_isRunning = false;

    for (auto server : m_servers)
    {
        delete server;
    }

    for (auto client : m_clients)
    {
        delete client;
    }
}

void MainServer::run()
{
    while (m_isRunning)
    {
        if (m_socketSelector.wait())
        {
            m_listenerHandler.handle();
            m_serversHandler.handle();
            m_clientsHandler.handle();
        }
    }
}