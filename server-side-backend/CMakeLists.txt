cmake_minimum_required(VERSION 3.0)

project(TicTacToeAPP)

add_executable(TicTacToeAPP
    source/main.cpp
    source/Application/Board.cpp
    source/Application/Entaglement.cpp
    source/Application/Tile.cpp)

target_link_libraries(TicTacToeAPP restbed)

target_include_directories(TicTacToeAPP PUBLIC ${CMAKE_SOURCE_DIR}/headers/Application)

set_property(TARGET TicTacToeAPP PROPERTY CXX_STANDARD 20)

