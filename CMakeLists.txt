cmake_minimum_required(VERSION 3.18.4)

project(Spark_Server)

set(INCROOT include)
set(SRCROOT src)

set(ALL_SRC
    ${SRCROOT}/Main.cpp
    ${INCROOT}/MainServer.hpp
    ${SRCROOT}/MainServer.cpp

    ${INCROOT}/Core/Client.hpp
    ${SRCROOT}/Core/Client.cpp
    ${INCROOT}/Core/Server.hpp
    ${SRCROOT}/Core/Server.cpp
    ${INCROOT}/Core/ClientsDB.hpp
    ${SRCROOT}/Core/ClientsDB.cpp
    ${INCROOT}/Core/ServersDB.hpp
    ${SRCROOT}/Core/ServersDB.cpp

    ${INCROOT}/Handlers/ConsoleHandler.hpp
    ${SRCROOT}/Handlers/ConsoleHandler.cpp
)

add_executable(${PROJECT_NAME} ${ALL_SRC})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCROOT} ${INCROOT}/Core ${INCROOT}/Handlers)

if(WIN32)
	add_subdirectory(extlibs/SFML)
else()
	find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)
endif(WIN32)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
