cmake_minimum_required(VERSION 3.29)

project(TextBasedPrototype)

set(CMAKE_CXX_STANDARD 20)

add_executable(game 
    src/main.cpp
    src/Game.cpp
    src/Logger.cpp
    src/Character.cpp
    src/Player.cpp
    src/NPC.cpp
    src/States.cpp
    src/Output.cpp
    src/Room.cpp
    src/Adjectives.cpp
)

target_include_directories(game PRIVATE include)