#pragma once

#include <iosfwd>

class Server
{
public:
    Server(unsigned id);
    ~Server();

private:
    unsigned m_id;

    friend std::ostream& operator<<(std::ostream& out, Server& server);
};

std::ostream& operator<<(std::ostream& out, Server& server);