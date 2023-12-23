#include "../headers/Application/Board.hpp"
#include <iostream>

int main()
{
    std::cout<<"Hello World!"<<std::endl;

    Board* board = new Board(3);

    std::cout<<*board<<std::endl;

    return 0;
}