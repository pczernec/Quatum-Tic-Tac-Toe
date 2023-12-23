#pragma once

#include "Sign.hpp"
#include <memory>

class Tile;

class Entaglement {
    public:
        Entaglement(Sign sign, std::shared_ptr<Tile> tile1, std::shared_ptr<Tile> tile2);
        std::shared_ptr<Tile> get_next_tile(std::shared_ptr<Tile> call_tile);


    private:
        const int sign;
        const std::shared_ptr<Tile> tile1;
        const std::shared_ptr<Tile> tile2;
};