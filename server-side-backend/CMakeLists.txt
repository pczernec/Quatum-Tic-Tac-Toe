cmake_minimum_required(VERSION 3.0)

project(TicTacToeAPP)

#TODO: check if it is possible to split this to 2 objects
add_executable(TicTacToeAPP
    source/main.cpp
    source/Application/GamesContainer.cpp
    source/Application/Game.cpp
    source/Application/Board.cpp
    source/Application/Entanglement.cpp
    source/Application/Tile.cpp
    source/API/GameResourceFactory.cpp
    source/API/CreateGameResourceFactory.cpp
    source/API/MakeMoveResourceFactory.cpp
    source/API/GameServiceSettingsFactory.cpp
    source/API/GameService.cpp
    )


target_link_libraries(TicTacToeAPP restbed)

target_include_directories(TicTacToeAPP PUBLIC ${CMAKE_SOURCE_DIR}/headers/Application ${CMAKE_SOURCE_DIR}/headers/API)

set_property(TARGET TicTacToeAPP PROPERTY CXX_STANDARD 20)

