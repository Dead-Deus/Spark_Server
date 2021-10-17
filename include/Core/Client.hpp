#pragma once

#include <iosfwd>

class Client
{
public:
    Client(unsigned id);
    ~Client();

private:
    unsigned m_id;

    friend std::ostream& operator<<(std::ostream& out, Client& client);
};

std::ostream& operator<<(std::ostream& out, Client& client);