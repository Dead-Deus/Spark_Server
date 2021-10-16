#pragma once

#include <vector>

class Client;

class ClientsDB
{
public:
    static ClientsDB& getInstance();

    Client& createClient();
    Client& getClient(unsigned id);

private:
    ClientsDB() = default;

    std::vector<Client*> m_clients;
};
