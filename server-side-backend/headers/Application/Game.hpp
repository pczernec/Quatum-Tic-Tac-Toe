#pragma once

#include "Board.hpp"


class Game {
    public:
        Game(int game_id, int n, int players_number);
        int get_id();
        int get_status();
        Sign get_turn();
        bool change_turn();
        std::shared_ptr<Board> get_board();

        bool start();
        bool make_move(Sign sign, int tile1_idx, int tile2_idx);

    private:
        int id;
        int status = 0;
        int players = 0;
        Sign turn = Sign(0);
        std::shared_ptr<Board> board;
};