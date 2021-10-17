#pragma once

#include <vector>
#include <iosfwd>

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

    friend std::ostream& operator<<(std::ostream& out, ClientsDB& clientsDB);
};

std::ostream& operator<<(std::ostream& out, ClientsDB& clientsDB);