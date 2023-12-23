#include "../../headers/Application/GamesContainer.hpp"

GamesContainer::GamesContainer() : games_counter(0) {};

int GamesContainer::generate_id(){
    games_counter += 1;
    return games_counter;
}

std::shared_ptr<Game> GamesContainer::create_game(int n, int players_number)
{
    int id = generate_id();
    std::shared_ptr<Game> game = std::make_shared<Game>(id, n, players_number);
    games.push_back(game);
    return game;
}

std::shared_ptr<Game> GamesContainer::get_game(int game_id)
{
    for(std::vector<std::shared_ptr<Game>>::iterator i = games.begin(); i != games.end(); i++)
    {
        if(i->get()->get_id()==game_id)
            return *i;
    }
    return nullptr;
}

