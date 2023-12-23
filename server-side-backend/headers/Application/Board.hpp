#pragma once

#include "Tile.hpp"

#include <sstream>

class Board {
    public:
        Board(int n);

        bool make_entanglement(Sign sign, int title1_idx, int title2_idx);
        bool check_for_cycles() const;
        bool check_for_winner() const;



        int get_size() const;

        const Tile* get_tile(int i);

        json to_json();
        friend std::ostream& operator<<(std::ostream& out, const Board& board );

    private:
        int n;
        //TODO: change to Tile* to shared_ptr?
        std::unique_ptr<Tile*[]> tiles_table;

};