#include "Board.hpp"
#include <cmath>

Board::Board(int n) : n(n)
{
    tiles_table = std::make_unique<Tile*[]>(pow(n, 2));
    for(int i=0; i<pow(n, 2); i++)
    {
        tiles_table[i] = new Tile(i);
    }
}

int Board::get_size() const
{
    return n;
}

const Tile* Board::get_tile(int i)
{
    return tiles_table[i];
}


bool Board::make_entanglement(Sign sign, int title1_idx, int title2_idx)
{
    return true;
}

bool Board::check_for_cycles() const
{
    return false;
}

bool Board::check_for_winner() const
{
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