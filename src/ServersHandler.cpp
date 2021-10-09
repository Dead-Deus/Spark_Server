#include "ServersHandler.hpp"

#include <iostream>

ServersHandler::ServersHandler(sf::SocketSelector& socketSelector, std::list<Server*>& servers) : m_socketSelector(socketSelector), m_servers(servers)
{
}

ServersHandler::~ServersHandler()
{
}

void ServersHandler::handle()
{
    for (auto server : m_servers)
    {
        auto& udpSocket = server->getUdpSocket();

        if (m_socketSelector.isReady(udpSocket))
        {
            sf::IpAddress  senderIp;
            unsigned short senderPort;

            if (udpSocket.receive(m_packet, senderIp, senderPort) == sf::Socket::Done)
            {
                handleMessage(*server, senderIp, senderPort);
                m_packet.clear();
            }
            else
            {
                std::cerr << "ServersHandler::handle()::[ Error can`t receive packet! ip: " << senderIp << " port: " << senderPort << "]"
                          << std::endl;
            }
        }
    }
}

void ServersHandler::handleMessage(Server& server, const sf::IpAddress& senderIp, const unsigned short senderPort)
{
    std::string command;
    m_packet >> command;

    if (command == "printMessage")
    {
        std::string message;
        m_packet >> message;
        server.printMessage(message, senderIp, senderPort);
    }
    else
    {
        std::cerr << "ServersHandler::handleMessage()::[ Error can`t find command: " << command << "]" << std::endl;
    }
}