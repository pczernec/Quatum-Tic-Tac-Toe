#pragma once

#include "IResourceFactory.hpp"
#include "../json.hpp"
#include "../Application/GamesContainer.hpp"

#include <tuple>
#include <string>


class GameResourceFactory : public IResourceFactory {

    public:
        GameResourceFactory(shared_ptr<GamesContainer> games_container);
        shared_ptr<Resource> get_resource() const final;

    private:
        shared_ptr<Resource> _game_resource;
        void get_game_handler(const shared_ptr<Session> session);
        int get_game_id(const shared_ptr<Session> session);
        shared_ptr<GamesContainer> games_container;
};