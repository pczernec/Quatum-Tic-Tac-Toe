#pragma once

#include "Sign.hpp"
#include <memory>

class Tile;

class Entanglement {
    public:
        Entanglement(Sign sign, std::shared_ptr<Tile> tile1, std::shared_ptr<Tile> tile2);
        std::shared_ptr<Tile> get_next_tile(std::shared_ptr<Tile> call_tile);

        Sign get_sign();

    private:
        const Sign sign;
        const std::shared_ptr<Tile> tile1;
        const std::shared_ptr<Tile> tile2;
};