#pragma once

#include "Tile.hpp"

#include "../json.hpp"

#include <sstream>
#include <iomanip>

class Board {
    public:
        Board(int n);

        bool make_entaglement(Sign sign, int title1_idx, int title2_idx);
        const bool check_for_cycles();
        const bool check_for_winner();

        friend std::ostringstream& operator<<(std::ostringstream& out, const Board& board );

    //private:
        int n;
        std::unique_ptr<Tile*[]> tiles_table;

};