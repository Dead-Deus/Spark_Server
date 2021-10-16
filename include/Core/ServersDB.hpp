#pragma once

#include <vector>

class Server;

class ServersDB
{
public:
    static ServersDB& getInstance();

    Server& createServer();
    Server& getServer(unsigned id);

private:
    ServersDB() = default;

    std::vector<Server*> m_servers;
};
