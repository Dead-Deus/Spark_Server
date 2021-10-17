#include "ConsoleHandler.hpp"

#include <iostream>

#include "ClientsDB.hpp"
#include "ServersDB.hpp"

ConsoleHandler::ConsoleHandler()
{
}

ConsoleHandler::~ConsoleHandler()
{
}

void ConsoleHandler::handle()
{
    std::string command;
    std::cin >> command;

    if (command == "help")
    {
        std::cout << "create_server" << std::endl;
        std::cout << "show_all_clients" << std::endl;
        std::cout << "show_all_servers" << std::endl;
    }
    else if (command == "create_server")
    {
        ServersDB::getInstance().createServer();
    }
    else if (command == "show_all_clients")
    {
        std::cout << ClientsDB::getInstance();
    }
    else if (command == "show_all_servers")
    {
        std::cout << ServersDB::getInstance();
    }
    else
    {
        std::cout << "ConsoleHandler::handle()::[ Can`t find Command:[" << command << "] ]" << std::endl;
    }
}