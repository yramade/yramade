// src/hooks/reducer.ts
import type { Action, State } from '../types/todo';
import { v4 as uuidv4 } from 'uuid';

export const initialState: State = {
  todos: [],
  filter: 'ALL'
};

export function useTodo(state: State, action: Action): State {
  switch (action.type) {
    case 'ADD_TODO': {
      const newTodo = {
        id: uuidv4(),
        text: action.payload.text,
        completed: false,
        dueDate: action.payload.dueDate,
        priority: action.payload.priority ?? 'medium',
      };
      return {
        ...state,
        todos: [...state.todos, newTodo],
      };
    }
    case 'TOGGLE_TODO': {
      return {
        ...state,
        todos: state.todos.map((todo) =>
          todo.id === action.payload ? { ...todo, completed: !todo.completed } : todo
        ),
      };
    }
    case 'DELETE_TODO': {
      return {
        ...state,
        todos: state.todos.filter((todo) => todo.id !== action.payload),
      };
    }
    case 'EDIT_TODO': {
      return {
        ...state,
        todos: state.todos.map((todo) =>
          todo.id === action.payload.id ? { ...todo, text: action.payload.text } : todo
        ),
      };
    }
    case 'CLEAR_COMPLETED': {
      return {
        ...state,
        todos: state.todos.filter((todo) => !todo.completed),
      };
    }
    case 'REORDER_TODOS': {
      return {
        ...state,
        todos: action.payload,
      };
    }
    default:
      return state;
  }
}
