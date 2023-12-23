#include "../../headers/API/CreateGameResourceFactory.hpp"

#include <sstream>
#include <iomanip>

//TODO: move this to another place and maybe change on to_string method
string bytes_to_string(int size, const Byte* start){
    string content="";
    for(int i=0; i<size; i++)
    {
        content += (char) *(start+i);
    }
    return content;
}


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
    ostringstream board_stream;
    board_stream<<*board;
    Sign currPlayer = game->get_turn();

    json response_json = {{"gameId", id}, {"status", status}, {"board", board_stream.str()}, {"currentPlayer", currPlayer} };
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
