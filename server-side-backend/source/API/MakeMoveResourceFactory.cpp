#include "../../headers/API/MakeMoveResourceFactory.hpp"

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

MakeMoveResourceFactory::MakeMoveResourceFactory(shared_ptr<GamesContainer> games_container)
    : games_container(games_container) {

    _game_resource = make_shared<Resource>();
    _game_resource->set_path(
        "/games/{id: [0-9]*}/MakeMove"
    );

    _game_resource->set_method_handler("POST", [&](const shared_ptr<Session> session){
        post_make_move_handler(session);
    });
};

shared_ptr<Resource> MakeMoveResourceFactory::get_resource() const {
    return _game_resource;
}

int MakeMoveResourceFactory::get_game_id(const shared_ptr<Session> session)
{
    const auto& request = session->get_request();
    int id = atoi(request->get_path_parameter("id").c_str());
    return id;
}

void MakeMoveResourceFactory::make_response(const shared_ptr< Session > session, const Bytes & body)
{
    string params = bytes_to_string(body.size(), body.data());
    json json_params = nlohmann::json::parse(params);

    Sign player = json_params.at("player");
    int tile_idx1 = json_params.at("idx1");
    int tile_idx2 = json_params.at("idx2");

    int id = get_game_id(session);

    shared_ptr<Game> game = games_container->get_game(id);

    game->make_move(player, tile_idx1, tile_idx2);

    int status = game->get_status();
    shared_ptr<Board> board = game->get_board();
    json board_json = board->to_json();
    Sign currPlayer = game->get_turn();
    string board_string = board_json.dump();

    json response_json = { {"status", status}, {"board", board_json.at("board")}, {"currentPlayer", currPlayer} };

    string response = response_json.dump();
    session->close( OK, response, { { "Content-Length", to_string(response.size()) } } );
}

//TODO move to base class
void MakeMoveResourceFactory::post_make_move_handler(const shared_ptr<Session> session) {
    const auto request = session->get_request();

    int content_length = request->get_header( "Content-Length", 0);

    session->fetch( content_length, [&]( const shared_ptr< Session > session, const Bytes & body )
    {
        make_response(session, body);
    } );
}
