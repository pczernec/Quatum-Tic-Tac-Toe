#include "Tile.hpp"
#include "Entaglement.hpp"

Tile::Tile(int idx) : classical_sign(Sign(0)), index(idx)
{

}

bool Tile::add_entaglement(const std::shared_ptr<Entaglement> entaglement)
{
    entaglements.push_back(entaglement);
    return true;
}

const std::vector<Sign> Tile::get_signs()
{
    return { classical_sign };
}