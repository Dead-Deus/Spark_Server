#include "ClientsHandler.hpp"

#include <iostream>
#include <string>
#include <limits>

#include "Config.hpp"
#include "Utils.hpp"

ClientsHandler::ClientsHandler(sf::SocketSelector& socketSelector, std::list<Server*>& servers, std::list<Client*>& clients) :
m_socketSelector(socketSelector),
m_servers(servers),
m_clients(clients)
{
}

ClientsHandler::~ClientsHandler()
{
}

void ClientsHandler::handle()
{
    for (auto client : m_clients)
    {
        auto& tcpSocket = client->getTcpSocket();

        if (m_socketSelector.isReady(tcpSocket))
        {
            if (tcpSocket.receive(m_packet) == sf::Socket::Done)
            {
                handleMessage(*client);
                m_packet.clear();
            }
            else
            {
                disconnectFromServer(*client);
                break;
            }
        }
    }
}

void ClientsHandler::handleMessage(Client& client)
{
    std::string command;
    m_packet >> command;

    if (command == "createServer")
    {
        createServer();
    }
    else if (command == "connectToServer")
    {
        connectToServer(client);
    }
    else
    {
        std::cerr << "ClientsHandler::handleMessage()::[ Error can`t find command: " << command << "]" << std::endl;
    }

    std::cout << std::endl;
}

void ClientsHandler::createServer()
{
    static unsigned short port = cfg::mainServerPort + 1;

    if (port >= std::numeric_limits<unsigned short>().max())
    {
        std::cerr << "ClientsHandler::createServer()::[ Max count servers! ]" << std::endl;
        return;
    }

    std::cout << "ClientsHandler::createServer()::[ port: " << port << "]" << std::endl;

    auto server = new Server(port++);

    m_socketSelector.add(server->getUdpSocket());
    m_servers.push_back(server);
}

void ClientsHandler::destroyServer()
{
}

void ClientsHandler::connectToServer(Client& client)
{
    auto serverUdpPort = utils::getConvertedPacketParameter<unsigned short>(m_packet);
    client.setServerUdpPort(serverUdpPort);

    auto server = findServer(serverUdpPort);

    unsigned short clientUdpPort = utils::getConvertedPacketParameter<unsigned short>(m_packet);

    std::cout << "ClientsHandler::connectToGameServer()::[ Ip: " << client.getTcpSocket().getRemoteAddress().toString() << " port: " << clientUdpPort
              << "]" << std::endl;

    client.setUdpPort(clientUdpPort);
    server->addClient(client);
}

void ClientsHandler::disconnectFromServer(Client& disconnectedClient)
{
    std::cout << "ClientsHandler::disconnectClient()::[Ip: " << disconnectedClient.getTcpSocket().getRemoteAddress()
              << " port: " << disconnectedClient.getTcpSocket().getRemotePort() << "]" << std::endl;

    auto server = findServer(disconnectedClient.getServerUdpPort());

    server->removeClient(disconnectedClient);
    m_clients.remove_if([&](Client* client) { return client == &disconnectedClient; });
}

Server* ClientsHandler::findServer(unsigned short serverUdpPort)
{
    auto serverIt = std::find_if(m_servers.begin(), m_servers.end(), [&](Server* server) { return server->getUdpPort() == serverUdpPort; });

    if (serverIt == m_servers.end())
    {
        std::cerr << "ClientsHandler::findServer()::[ Can`t find game server on port: " << serverUdpPort << "]" << std::endl;
    }

    return *serverIt;
}