#include "../../headers/API/GameResourceFactory.hpp"

#include <sstream>
#include <iomanip>

GameResourceFactory::GameResourceFactory(shared_ptr<GamesContainer> games_container)
    : games_container(games_container) {

    _game_resource = make_shared<Resource>();
    _game_resource->set_path(
        "/get_game/{id: [0-9]*}"
    );

    _game_resource->set_method_handler("GET", [&](const shared_ptr<Session> session){
        get_game_handler(session);
    });
};

shared_ptr<Resource> GameResourceFactory::get_resource() const {
    return _game_resource;
}


int GameResourceFactory::get_game_id(const shared_ptr<Session> session)
{
    const auto& request = session->get_request();
    int id = atoi(request->get_path_parameter("id").c_str());
    return id;
}

void GameResourceFactory::get_game_handler(const shared_ptr<Session> session) {
    const int game_id = get_game_id(session);
    shared_ptr<Game> game = games_container->get_game(game_id);

    //TODO: sperate this to function (base class)
    int status = game->get_status();
    json board_json = game->get_board()->to_json();
    Sign currentPlayer = game->get_turn();

    json response_json =  { {"status", status}, {"board", board_json["board"]}, {"currentPlayer", currentPlayer}};
    string response = response_json.dump();

    session->close(OK, response,
        {{"Content-Length", to_string(response.size())}});

}