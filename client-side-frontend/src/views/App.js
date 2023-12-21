import { BrowserRouter, Route, Routes } from 'react-router-dom';
import '../stylesheets/App.scss';
import Start from './Start';
import Game from './Game';



function App() {
  return (

  <BrowserRouter>
    <Routes>
      <Route index element={<Start />} />
      <Route path="games/:gameId" element={<Game />} />
    </Routes>
  </BrowserRouter>

  );
}

export default App;
