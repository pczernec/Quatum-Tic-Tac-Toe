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

json Tile::to_json()
{
    json tile_json;
    return tile_json;
}

std::ostream& operator<<(std::ostream& stream, Tile& tile)
{
    std::vector<Sign> signs = tile.get_signs();
    stream<<"[ ";
    for( std::vector<Sign>::iterator i = signs.begin(); i != signs.end(); i++)
    {
        stream<<*i<<" ";
    }
    stream<<"]";
    return stream;
}