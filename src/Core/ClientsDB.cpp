#include "ClientsDB.hpp"

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