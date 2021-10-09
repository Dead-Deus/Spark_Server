cmake_minimum_required(VERSION 3.18.4)

project(Spark_Server)

set(INCROOT include)
set(SRCROOT src)

set(ALL_SRC
    ${SRCROOT}/Main.cpp
    ${INCROOT}/MainServer.hpp
    ${SRCROOT}/MainServer.cpp
    ${INCROOT}/ListenerHandler.hpp
    ${SRCROOT}/ListenerHandler.cpp
    ${INCROOT}/ServersHandler.hpp
    ${SRCROOT}/ServersHandler.cpp
    ${INCROOT}/ClientsHandler.hpp
    ${SRCROOT}/ClientsHandler.cpp
    ${INCROOT}/Server.hpp
    ${SRCROOT}/Server.cpp
    ${INCROOT}/Client.hpp
    ${SRCROOT}/Client.cpp

    ${INCROOT}/Utils/Config.hpp
    ${INCROOT}/Utils/Utils.hpp
    ${INCROOT}/Utils/Utils.inl
    ${SRCROOT}/Utils/Utils.cpp
)

add_executable(${PROJECT_NAME} ${ALL_SRC})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCROOT} ${INCROOT}/Utils)

add_subdirectory(extlibs/SFML)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network)
