#include "Server.hpp"

#include <iostream>
#include <string>
#include <sstream>

Server::Server(const unsigned short udpPort) : m_udpPort(udpPort)
{
    if (m_udpSocket.bind(m_udpPort) != sf::Socket::Done)
    {
        std::cerr << "Server::Server::[ Error can`t bind socket to port: " << m_udpPort << "]" << std::endl;
    }
}

Server::~Server()
{
}

void Server::printMessage(const std::string& message, const sf::IpAddress& senderIp, const unsigned short senderPort)
{
    std::cout << "Server::printMessage()" << std::endl;

    m_packet << "printMessage";
    m_packet << message;
    m_packet << senderIp.toString();

    std::string portText;

    std::stringstream ss;
    ss << senderPort;
    ss >> portText;
    m_packet << portText;

    for (auto& client : m_clients)
    {
        m_udpSocket.send(m_packet, client->getTcpSocket().getRemoteAddress(), client->getUdpPort());
    }

    m_packet.clear();
}

void Server::addClient(Client& client)
{
    std::cout << "Server::addClient::()[ Ip: " << client.getTcpSocket().getRemoteAddress().toString() << " port: " << client.getUdpPort() << "]"
              << std::endl;
    m_clients.push_back(&client);
}

void Server::removeClient(Client& disconnectedClient)
{
    std::cout << "Server::removeClient()::[ Remove client udp port: " << disconnectedClient.getUdpPort() << "]" << std::endl;
    auto it = std::find_if(m_clients.begin(), m_clients.end(), [&](Client* client) { return client == &disconnectedClient; });

    if (it == m_clients.end())
    {
        std::cerr << "Server::removeClient()::[ Can`t find client ]" << std::endl;
        return;
    }

    m_clients.erase(it);
}

sf::UdpSocket& Server::getUdpSocket()
{
    return m_udpSocket;
}

unsigned short Server::getUdpPort() const
{
    return m_udpPort;
}