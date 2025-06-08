import { describe, it, expect } from 'vitest';
import { useTodo, initialState } from '../hooks/useTodo';
import type { Todo } from '../types/todo';

describe('reducer', () => {
  it('should add a todo with text, dueDate, and priority', () => {
    const newState = useTodo(initialState, {
      type: 'ADD_TODO',
      payload: {
        text: '할 일',
        dueDate: '2025-06-01',
        priority: 'high',
      },
    });

    expect(newState.todos.length).toBe(1);
    expect(newState.todos[0].text).toBe('할 일');
    expect(newState.todos[0].dueDate).toBe('2025-06-01');
    expect(newState.todos[0].priority).toBe('high');
  });

  it('should toggle a todo', () => {
    const state = {
      ...initialState,
      todos: [{ id: '1', text: '일', completed: false }],
    };

    const newState = useTodo(state, {
      type: 'TOGGLE_TODO',
      payload: '1',
    });

    expect(newState.todos[0].completed).toBe(true);
  });

  it('should delete a todo', () => {
    const state = {
      ...initialState,
      todos: [{ id: '1', text: '일', completed: false }],
    };

    const newState = useTodo(state, {
      type: 'DELETE_TODO',
      payload: '1',
    });

    expect(newState.todos.length).toBe(0);
  });

  it('should edit a todo', () => {
    const state = {
      ...initialState,
      todos: [{ id: '1', text: '기존', completed: false }],
    };

    const newState = useTodo(state, {
      type: 'EDIT_TODO',
      payload: { id: '1', text: '수정됨' },
    });

    expect(newState.todos[0].text).toBe('수정됨');
  });

  it('should clear completed todos', () => {
    const state = {
      ...initialState,
      todos: [
        { id: '1', text: '완료됨', completed: true },
        { id: '2', text: '미완료', completed: false },
      ],
    };

    const newState = useTodo(state, { type: 'CLEAR_COMPLETED' });

    expect(newState.todos.length).toBe(1);
    expect(newState.todos[0].text).toBe('미완료');
  });

  it('should reorder todos', () => {
    const state = {
      ...initialState,
      todos: [
        { id: '1', text: '첫째', completed: false },
        { id: '2', text: '둘째', completed: false },
      ],
    };

    const newState = useTodo(state, {
      type: 'REORDER_TODOS',
      payload: [state.todos[1], state.todos[0]],
    });

    expect(newState.todos[0].id).toBe('2');
    expect(newState.todos[1].id).toBe('1');
  });
});
