#include "../../headers/API/CreateGameResourceFactory.hpp"

#include <sstream>
#include <iomanip>


CreateGameResourceFactory::CreateGameResourceFactory(shared_ptr<GamesContainer> games_container)
    : games_container(games_container) {

    _game_resource = make_shared<Resource>();
    _game_resource->set_path(
        "/games/"
    );

    _game_resource->set_method_handler("POST", [&](const shared_ptr<Session> session){
        post_new_game_handler(session);
    });
};

shared_ptr<Resource> CreateGameResourceFactory::get_resource() const {
    return _game_resource;
}

void CreateGameResourceFactory::make_response(const shared_ptr< Session > session, const Bytes & body)
{
    string params = bytes_to_string(body.size(), body.data());
    json json_params = nlohmann::json::parse(params);

    int players_number = json_params.at("players");
    int n = json_params.at("boardSize");

    shared_ptr<Game> game = games_container->create_game(n, players_number);

    int id = game->get_id();
    int status = game->get_status();
    shared_ptr<Board> board = game->get_board();
    json board_json = board->to_json();
    Sign currPlayer = game->get_turn();
    string board_string = board_json.dump();

    json response_json = {{"gameId", id}, {"status", status}, {"board", board_json.at("board")}, {"currentPlayer", currPlayer} };

    string response = response_json.dump();
    session->close( OK, response, { { "Content-Length", to_string(response.size()) } } );
}

void CreateGameResourceFactory::post_new_game_handler(const shared_ptr<Session> session) {
    const auto request = session->get_request();

    int content_length = request->get_header( "Content-Length", 0);

    session->fetch( content_length, [&]( const shared_ptr< Session > session, const Bytes & body )
    {
        make_response(session, body);
    } );
}
