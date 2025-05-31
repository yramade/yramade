import { useEffect, useReducer } from 'react';
import { v4 as uuidv4 } from 'uuid';
import type { Todo, State, Action, Filter } from '../types/todo';

const initialState: State = { todos: [], filter: 'ALL' };

const todoReducer = (state: State, action: Action): State => {
  switch (action.type) {
    case 'INIT_TODO':
      return { todos: action.payload, filter: state.filter };
    case 'ADD_TODO':
      const newTodo: Todo = {
        id: uuidv4(),
        text: action.payload.text,
        completed: false,
        dueDate: action.payload.dueDate,
        priority: action.payload.priority,
      };
      return { ...state, todos: [...state.todos, newTodo], filter: state.filter };
    case 'TOGGLE_TODO':
      return {
        todos: state.todos.map(todo =>
          todo.id === action.payload
          ? { ...todo, completed: !todo.completed}
          : todo
        ),
        filter: state.filter
      };
    case 'DELETE_TODO':
      return {
        todos: state.todos.filter(todo => todo.id !== action.payload),
        filter: state.filter
      };
    case 'SET_FILTER':
    return {
      ...state,
      filter: action.payload,
    };
    case 'EDIT_TODO':
      const { id, text } = action.payload;
      return {
        ...state,
        todos: state.todos.map((todo) =>
        todo.id === id ? { ...todo, text } : todo )
      };
    case 'CLEAR_COMPLETED':
      return {
        ...state,
        todos: state.todos.filter((todo) => !todo.completed),
      };
    case 'REORDER_TODOS':
      return {
        ...state,
        todos: action.payload,
      };
    default:
      return state;
  }
};

export const useTodo = () => {
  const [state, dispatch] = useReducer(todoReducer, initialState);

  useEffect(() => {
    const stored = localStorage.getItem('todos');
    if(stored){
      dispatch({ type: 'INIT_TODO', payload: JSON.parse(stored)});
    }
  },[]);

  useEffect(() => {
    localStorage.setItem('todos', JSON.stringify(state.todos));
  },[state.todos]);

  return { state, dispatch };
};