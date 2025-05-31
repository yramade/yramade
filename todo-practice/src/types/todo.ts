export interface Todo {
  id: string;
  text: string;
  completed: boolean;
  dueDate?: string;        // YYYY-MM-DD 형식
  priority?: 'high' | 'medium' | 'low';
};

export type Filter = 'ALL' | 'COMPLETED' | 'INCOMPLETE';

export type State = {
  todos: Todo[];
  filter: Filter;
};

export type Action =
  | { type: 'INIT_TODO'; payload: Todo[] }
  | { type: 'ADD_TODO'; payload: { text: string; dueDate?: string; priority?: 'high' | 'medium' | 'low' } }
  | { type: 'DELETE_TODO'; payload: string }
  | { type: 'TOGGLE_TODO'; payload: string }
  | { type: 'SET_FILTER'; payload: Filter }
  | { type: 'EDIT_TODO'; payload: { id: string; text: string } }
  | { type: 'CLEAR_COMPLETED' }
  | { type: 'REORDER_TODOS'; payload: Todo[] };