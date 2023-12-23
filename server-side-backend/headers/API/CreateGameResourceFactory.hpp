#pragma once

#include "IResourceFactory.hpp"
#include "../json.hpp"
#include "../Application/GamesContainer.hpp"

#include <string>

using nlohmann::json;

class CreateGameResourceFactory : public IResourceFactory {

    public:
        CreateGameResourceFactory(shared_ptr<GamesContainer> games_container);
        shared_ptr<Resource> get_resource() const final;
        void make_response(const shared_ptr< Session > session, const Bytes & body);

    private:
        shared_ptr<Resource> _game_resource;
        void post_new_game_handler(const shared_ptr<Session> session);
        shared_ptr<GamesContainer> games_container;
};