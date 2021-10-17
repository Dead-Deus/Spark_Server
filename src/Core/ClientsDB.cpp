#include "ClientsDB.hpp"

#include <iostream>

#include "Client.hpp"

ClientsDB& ClientsDB::getInstance()
{
    static ClientsDB instance;
    return instance;
}

Client& ClientsDB::createClient()
{
    auto client = new Client(m_clients.size());
    m_clients.push_back(client);

    return *client;
}

Client& ClientsDB::getClient(unsigned id)
{
    return *m_clients[id];
}

std::ostream& operator<<(std::ostream& out, ClientsDB& clientsDB)
{
    for (auto client : clientsDB.m_clients)
    {
        out << "Client:[ " << *client << " ]" << std::endl;
    }
    return out;
}