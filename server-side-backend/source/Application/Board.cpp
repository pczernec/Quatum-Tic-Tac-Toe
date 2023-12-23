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

bool Board::make_entaglement(Sign sign, int title1_idx, int title2_idx)
{
    return true;
}

const bool Board::check_for_cycles()
{
    return false;
}

const bool Board::check_for_winner()
{
    return false;
}


// std::ostream& operator<<(std::ostream& stream, const Board& board)
// {

//     for(int i = 0; i < board.n; i++)
//     {
//         for(int j = 0; j < board.n; j++)
//         {
//             stream<<"["<<"0"<<"]";
//         }
//         stream<<std::endl;
//     }
//     return stream;
// }