#pragma once

#include <SFML/System/Thread.hpp>

#include "ConsoleHandler.hpp"

class MainServer
{
public:
    MainServer();
    ~MainServer();

    void run();

private:
    sf::Thread     m_consoleThread;
    ConsoleHandler m_consoleHandler;

    bool m_isRunning;
};
