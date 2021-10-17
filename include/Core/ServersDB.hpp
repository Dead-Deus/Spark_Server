#pragma once

#include <vector>
#include <iosfwd>

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

    friend std::ostream& operator<<(std::ostream& out, ServersDB& serversDB);
};

std::ostream& operator<<(std::ostream& out, ServersDB& serversDB);