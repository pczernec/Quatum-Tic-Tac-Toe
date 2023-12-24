import ToggleGroup from "../components/ToggleGroup";
import { useNavigate } from "react-router-dom";
import { useState } from "react";
import axios from "axios";


function BoardSizeButton( {value} )
{
    return (
    <button id="board-size-display" className="button" value={value}>{value}</button>
    )
}


function ChangeBoardSizeButton( {currentValue, changeSize, setNewValue, sizeStyle} )
{
    var text="";
    if(changeSize > 0)
    {
        text = "+";
    }
    text = text + changeSize;

    return (
        <button className={"button "+sizeStyle+"-change-button"} onClick={ () => {
            if(currentValue+changeSize<3)
            {
                alert("Board size value cannot be smaller than 3.");
            }
            else
            {
                setNewValue(currentValue+changeSize);
            }
        }

    }>{text}</button>
    )
}


function Start() {

    const playerModes = [1, 2];
    const boardSizeModes = [3, 5, 7, 10];

    const [playersNumber, setPlayersNumber] = useState(playerModes[0]);
    const [boardSize, setBoardSize] = useState(boardSizeModes[1]);


    const navigate = useNavigate();

    function playButtonHandler() {
        //TODO: error handling
        axios.post('/games', {
        players: playersNumber,
        boardSize: boardSize
          })
          .then(function (response) {
            console.log(response);
            const id =response.data.gameId;
            navigate("/games/" + id, {state: response.data});
          })
          .catch(function (error) {
            console.log(error);
          });
    }


    return (
        <div className="StartContainer App">
            <h1>Select a game mode</h1>
            <h2>Number of players</h2>
            <ToggleGroup options={playerModes}  className="bigSelector" active={playersNumber} setActive={setPlayersNumber} />
            <h2>Board size</h2>
            <div>
                <ChangeBoardSizeButton currentValue={boardSize} changeSize={-1} setNewValue={setBoardSize} sizeStyle="small" />
                <ChangeBoardSizeButton currentValue={boardSize} changeSize={-10} setNewValue={setBoardSize} sizeStyle="large" />
                <BoardSizeButton value={boardSize} />
                <ChangeBoardSizeButton currentValue={boardSize} changeSize={10} setNewValue={setBoardSize} sizeStyle="large" />
                <ChangeBoardSizeButton currentValue={boardSize} changeSize={1} setNewValue={setBoardSize} sizeStyle="small"/>
            </div>
            <button id="play-button" className="btn btn-lg btn-danger" onClick={playButtonHandler}>play</button>
        </div>
    )
}


export default Start;