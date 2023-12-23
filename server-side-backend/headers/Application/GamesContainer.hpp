#pragma once

#include "Game.hpp"



class GamesContainer{
    public:
        GamesContainer();
        std::shared_ptr<Game> create_game(int n, int players_number);
        std::shared_ptr<Game> get_game(int game_id);

    private:
        int generate_id();
        int games_counter;
        std::vector<std::shared_ptr<Game>> games;
};

