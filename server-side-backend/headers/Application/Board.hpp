#pragma once

#include "Tile.hpp"

#include "../json.hpp"

#include <sstream>

class Board {
    public:
        Board(int n);

        bool make_entaglement(Sign sign, int title1_idx, int title2_idx);
        const bool check_for_cycles();
        const bool check_for_winner();

        const int get_size();

        const Tile* get_tile(int i);

        friend std::ostream& operator<<(std::ostream& out, const Board& board );

    private:
        int n;
        //TODO: change to Tile* to shared_ptr?
        std::unique_ptr<Tile*[]> tiles_table;

};