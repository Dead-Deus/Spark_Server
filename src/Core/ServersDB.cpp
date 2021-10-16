#include "ServersDB.hpp"

#include "Server.hpp"

ServersDB& ServersDB::getInstance()
{
    static ServersDB instance;
    return instance;
}

Server& ServersDB::createServer()
{
    auto server = new Server(m_servers.size());
    m_servers.push_back(server);

    return *server;
}

Server& ServersDB::getServer(unsigned id)
{
    return *m_servers[id];
}