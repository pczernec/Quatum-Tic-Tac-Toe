#pragma once

#include "Sign.hpp"
#include <vector>
#include <memory>

class Entaglement;

class Tile {
    public:
        Tile(int idx);
        bool add_entaglement(const std::shared_ptr<Entaglement>);
        const std::vector<Sign> get_signs();

    private:
        int index;
        Sign classical_sign;
        std::vector<std::shared_ptr<Entaglement>> entaglements;

};