cmake_minimum_required(VERSION 3.9)
project(Server)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(Server main.cpp src/Server.cpp include/Server.h src/CommandsManager.cpp include/CommandsManager.h src/GameInfo.cpp include/GameInfo.h src/Command.cpp src/StartCommand.cpp include/StartCommand.h src/JoinCommand.cpp include/JoinCommand.h src/GameListCommand.cpp include/GameListCommand.h src/ServerGames.cpp include/ServerGames.h include/Task.h src/ThreadPool.cpp include/ThreadPool.h)