import { StrictMode } from 'react';
import { createRoot } from 'react-dom/client';
import { router } from './routes';
import './index.css';
import { RouterProvider } from 'react-router-dom';
// import App from './App.tsx';

createRoot(document.getElementById('root')!).render(
  <StrictMode>
    <RouterProvider router={router} />
    {/* <App /> */}
  </StrictMode>,
);
