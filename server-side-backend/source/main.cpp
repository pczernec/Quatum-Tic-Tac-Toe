#include "../headers/Application/Board.hpp"
#include <iostream>

int main()
{
    std::cout<<"Hello"<<std::endl;

    Board* board = new Board(3);

    std::cout<<board->tiles_table[0]->get_signs().back()<<std::endl;

    return 0;
}