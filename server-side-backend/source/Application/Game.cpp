#include "Game.hpp"

Game::Game(int game_id, int n, int players_number) : id(game_id), players(players_number){
    board =  std::make_shared<Board>(n);
}

bool Game::start()
{
    //players initialization (optional)
    status = 1;
    return true;
}


bool Game::make_move(Sign sign, int tile1_idx, int tile2_idx)
{
    board->make_entanglement(sign, tile1_idx, tile2_idx);
    board->check_for_cycles();
    board->check_for_winner();

    return true;
}

int Game::get_id()
{
    return id;
}


int Game::get_status()
{
    return status;
}

Sign Game::get_turn()
{
    return turn;
}

std::shared_ptr<Board> Game::get_board()
{
    return board;
}