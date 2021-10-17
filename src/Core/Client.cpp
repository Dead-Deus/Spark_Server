#include "Client.hpp"

#include <iostream>

Client::Client(unsigned id) : m_id(id)
{
}

Client::~Client()
{
}

std::ostream& operator<<(std::ostream& out, Client& client)
{
    std::cout << "Id:[" << client.m_id << "]";
    return out;
}
