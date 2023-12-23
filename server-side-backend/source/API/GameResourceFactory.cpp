#include "../../headers/API/GameResourceFactory.hpp"

#include <sstream>
#include <iomanip>

GameResourceFactory::GameResourceFactory(shared_ptr<GamesContainer> games_container)
    : games_container(games_container) {

    _game_resource = make_shared<Resource>();
    _game_resource->set_path(
        "/games/{id: [0-9]*}"
    );

    _game_resource->set_method_handler("GET", [&](const shared_ptr<Session> session){
        get_game_handler(session);
    });
};

shared_ptr<Resource> GameResourceFactory::get_resource() const {
    return _game_resource;
}


//TODO: move this method to new GameAPI class?
string GameResourceFactory::to_json(Board &board)
{
    ostringstream str_stream;
    str_stream<<board;
    nlohmann::json jsonBoard = {
        {"board", str_stream.str()}
    };
    return jsonBoard.dump();
}


int GameResourceFactory::get_game_id(const shared_ptr<Session> session)
{
    const auto& request = session->get_request();
    int id = atoi(request->get_path_parameter("id").c_str());
    return id;
}

void GameResourceFactory::get_game_handler(const shared_ptr<Session> session) {
    Board* board = new Board(3);
    const int game_id = get_game_id(session);
    string content = to_json(*board);
    session->close(OK, content,
        {{"Content-Length", to_string(content.size())}});

}