import { BrowserRouter, Route, Routes } from 'react-router-dom';
import '../stylesheets/App.css';
import Start from './Start';
import Game from './Game';

function App() {
  return (

  <BrowserRouter>
    <Routes>
      <Route index element={<Start />} />
      <Route path="game" element={<Game />} />
    </Routes>
  </BrowserRouter>

  );
}

export default App;
