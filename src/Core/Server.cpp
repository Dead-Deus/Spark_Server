#include "Server.hpp"

#include <iostream>

Server::Server(unsigned id) : m_id(id)
{
}

Server::~Server()
{
}

std::ostream& operator<<(std::ostream& out, Server& server)
{
    std::cout << "Id:[" << server.m_id << "]";
    return out;
}
