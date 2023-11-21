import ToggleGroup from '../components/ToggleGroup';
import { useNavigate } from 'react-router-dom';
import { useState } from 'react';
import axios from 'axios';

import '../stylesheets/Buttons.css'



function Start() {

    const playerModes = [1, 2]
    const boardSizeModes = [3, 5, 7, 10]

    const [playersNumber, setPlayersNumber] = useState(playerModes[0])
    const [boardSize, setBoardSize] = useState(boardSizeModes[0])


    const navigate = useNavigate();

    function playButtonHandler() {
        navigate('/game');
    }

    return (
        <div className="StartContainer App">
            <h1>Select a game mode</h1>
            <h2>Number of players</h2>
            <ToggleGroup options={playerModes}  className='bigSelector' active={playersNumber} setActive={setPlayersNumber} />
            <h2>Board size</h2>
            <ToggleGroup options={boardSizeModes} className='smallSelector' active={boardSize} setActive={setBoardSize}/>
            <button id='play' className='button' onClick={playButtonHandler}>play</button>
        </div>
    )
}


export default Start;