import Board from "../components/Board";
import { useLocation, useParams } from "react-router-dom";
import axios from "axios";

import "../stylesheets/Game.scss"
import { useState, useEffect } from "react";


function Game( props ) {

    function parseBoard(boardDict)
    {
        var newBoard = new Array();
        for(let i=0; i < Object.keys(boardDict).length; i++)
        {
            if(boardDict[i].ConstSign != 0)
                newBoard.push(boardDict[i].ConstSign);
            else
                newBoard.push("-");

        }
        return newBoard;
    }

    function getBoard()
    {
        axios.get('/get_game/' + gameId)
        .then(function (response) {
            // handle success
            setBoard(parseBoard(response.data.board))
        })
        .catch(function (error) {
           // handle error
           console.log(error);
           return [ 0 ];
        })
    }


    const location = useLocation();
    const [boardAction, setBoardAction] = useState([]);
    const {gameId} = useParams();

    let board=[ " " ];
    if(location.state != null)
        board=parseBoard(location.state.board);

    const [boardState, setBoard] = useState(board);

    function reload(setBoard)
    {
        getBoard();
    }

    function make_move(action)
    {
        //TODO
        console.log("MOVE")
        //getBoard(1);
    }


    return (
        <div className='App Game'>
            <h1>Game ID: {gameId}</h1>
            <div className="container">
                <Board board={boardState} boardAction={boardAction} setBoardAction={setBoardAction} playerSign="X" />
            </div>
            <div className="container">
                <button id="make-move" onClick={() => make_move(boardAction)} className="btn btn-outline-warning btn-lg">Make move</button>
            </div>
            <div className="container">
                <button onClick={() => reload(setBoard)} className="btn btn-danger btn-lg">Reload</button>
            </div>
        </div>
    )
}


export default Game;
