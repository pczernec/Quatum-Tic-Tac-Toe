import Board from "../components/Board";
import { useLocation, useParams } from "react-router-dom";
import axios from "axios";

import "../stylesheets/Game.scss"
import { useState } from "react";


function Game( props ) {

    const [boardAction, setBoardAction] = useState([]);

    const tileStates = ["-", "O", "X", "OX", "XO"];
    const {gameId} = useParams();

    let currBoard = ["-", "-", "-", "-", "-", "-", "-", "-", "-"];
    const [board, setBoard] = useState(currBoard);

    //axios.get('/games/' + gameId)
    //    .then(function (response) {
    //        // handle success
    //        currBoard = response.board;
    //    })
    //    .catch(function (error) {
    //        // handle error
    //        console.log(error);
    //    })
    //    .finally(function () {
    //        // always executed
    //    });


    return (
        <div className='App Game'>
            <h1>Game ID: {gameId}</h1>
            <div className="container">
                <Board board={board} boardAction={boardAction} setBoardAction={setBoardAction} playerSign="X" />
            </div>
            <div className="container">
                <button id="make-move" className="btn btn-outline-warning btn-lg">Make move</button>
            </div>
        </div>
    )
}


export default Game;
