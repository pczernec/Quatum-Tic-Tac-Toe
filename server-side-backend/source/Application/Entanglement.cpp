#include "Entanglement.hpp"
#include "Tile.hpp"

Entanglement::Entanglement(Sign sign, std::shared_ptr<Tile> tile1, std::shared_ptr<Tile> tile2) : sign(sign), tile1(tile1), tile2(tile2)
{
    //add_entanglement to tiles here (?)
}


Sign Entanglement::get_sign()
{
    return sign;
}

std::shared_ptr<Tile> Entanglement::get_next_tile(std::shared_ptr<Tile> call_tile)
{
    if(tile1 == call_tile)
    {
        return tile2;
    }
    else
    {
        return tile1;
    }
}