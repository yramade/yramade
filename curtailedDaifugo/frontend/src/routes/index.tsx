import { createBrowserRouter } from 'react-router-dom';
import Home from '../pages/Home';
import Game from '../pages/Game';
import Result from '../pages/Result';

export const router = createBrowserRouter([
  { path: '/', element: <Home /> },
  { path: '/game', element: <Game /> },
  { path: '/result', element: <Result /> },
]);
