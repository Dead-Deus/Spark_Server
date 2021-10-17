#include "MainServer.hpp"

MainServer::MainServer() :
m_consoleThread(
    [&]()
    {
        while (m_isRunning)
        {
            m_consoleHandler.handle();
        }
    }),
m_isRunning(false)
{
}

MainServer::~MainServer()
{
}

void MainServer::run()
{
    m_isRunning = true;

    m_consoleThread.launch();

    m_consoleThread.wait();
}