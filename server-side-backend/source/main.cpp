#include "../headers/Application/GamesContainer.hpp"
#include "../headers/API/GameResourceFactory.hpp"
#include "../headers/API/CreateGameResourceFactory.hpp"
#include "../headers/API/GameServiceSettingsFactory.hpp"
#include "../headers/API/GameService.hpp"
#include <iostream>


int main()
{
    shared_ptr<GamesContainer> games_container = make_shared<GamesContainer>();
    shared_ptr<Game> game = games_container->create_game(4, 1);
    game->make_move(Sign::X, 0, 4);
    game->make_move(Sign::X, 0, 5);

    auto resource_factory = make_shared<GameResourceFactory>(games_container);
    auto resource_factory2 = make_shared<CreateGameResourceFactory>(games_container);
    auto settings_factory = make_shared<GameServiceSettingsFactory>();

    GameService service {resource_factory, resource_factory2, settings_factory};

    service.start();


    return 0;
}