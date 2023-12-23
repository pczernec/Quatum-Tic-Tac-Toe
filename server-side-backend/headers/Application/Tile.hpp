#pragma once

#include "Sign.hpp"
#include "../json.hpp"
#include <string>
#include <vector>
#include <memory>

class Entanglement;

using nlohmann::json;

class Tile {
    public:
        Tile(int idx);
        bool add_entanglement(const std::shared_ptr<Entanglement>);
        std::vector<Sign> get_signs();

        json to_json();

        friend std::ostream& operator<<(std::ostream& stream, Tile& tile);

    private:
        int index;
        Sign const_sign;
        std::vector<std::shared_ptr<Entanglement>> entanglements;

};