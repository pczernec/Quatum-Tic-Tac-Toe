#include "../headers/Application/Board.hpp"
#include "../headers/API/GameResourceFactory.hpp"
#include "../headers/API/GameServiceSettingsFactory.hpp"
#include "../headers/API/GameService.hpp"
#include <iostream>

int main()
{
    auto resource_factory = make_shared<GameResourceFactory>();
    auto setting_factory = make_shared<GameServiceSettingsFactory>();

    GameService service {resource_factory, setting_factory};

    service.start();


    return 0;
}