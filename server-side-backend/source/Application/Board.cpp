#include "Board.hpp"
#include <cmath>
#include <iostream>

Board::Board(int n) : n(n)
{
    tiles_table = std::make_unique<std::shared_ptr<Tile>[]>(pow(n, 2));
    for(int i=0; i<pow(n, 2); i++)
    {
        tiles_table[i] = std::make_shared<Tile>(i);
    }
}

int Board::get_size() const
{
    return n;
}

std::shared_ptr<Tile> Board::get_tile(int i)
{
    return tiles_table[i];
}


bool Board::make_entanglement(Sign sign, int tile1_idx, int tile2_idx)
{
    //TODO checking if correct move
    //TODO move add_entanglement to entanglement consturctor ?
    std::shared_ptr<Entanglement> entanglement = std::make_shared<Entanglement>(sign, tiles_table[tile1_idx], tiles_table[tile2_idx]);
    tiles_table[tile1_idx]->add_entanglement(entanglement);
    tiles_table[tile2_idx]->add_entanglement(entanglement);

    return true;
}

bool Board::check_for_cycles() const
{
    //TODO
    return false;
}

bool Board::check_for_winner() const
{
    //TODO
    return false;
}

json Board::to_json()
{
    json board_json;
    for(int i = 0; i < pow(n, 2); i++)
    {
        board_json["board"][std::to_string(i)] = tiles_table[i]->to_json();
    }
    return board_json;
}

std::ostream& operator<<(std::ostream& stream, const Board& board)
{
    for(int i = 0; i < board.n; i++)
    {
        for(int j = 0; j < board.n; j++)
        {
            stream<<*board.tiles_table[i*board.n + j];
        }
        stream<<std::endl;
    }
    return stream;
}