#pragma once

#include "Sign.hpp"
#include "../json.hpp"
#include <vector>
#include <memory>

class Entaglement;

using nlohmann::json;

class Tile {
    public:
        Tile(int idx);
        bool add_entaglement(const std::shared_ptr<Entaglement>);
        const std::vector<Sign> get_signs();

        json to_json();

        friend std::ostream& operator<<(std::ostream& stream, Tile& tile);

    private:
        int index;
        Sign classical_sign;
        std::vector<std::shared_ptr<Entaglement>> entaglements;

};