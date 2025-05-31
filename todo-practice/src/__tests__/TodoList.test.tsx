import { describe, it, expect, vi } from 'vitest';
import { render, screen, fireEvent } from '@testing-library/react';
import TodoList from '../components/TodoList';
import type { Todo } from '../types/todo';
import { I18nextProvider } from 'react-i18next';
import i18n from '../i18n';

describe('TodoList', () => {
  const baseTodos: Todo[] = [
    {
      id: '1',
      text: '할 일 1',
      completed: false,
      dueDate: '2025-06-01',
      priority: 'medium',
    },
  ];

  it('renders todo item with text, dueDate, and priority', () => {
    render(
      <I18nextProvider i18n={i18n}>
        <TodoList
          todos={baseTodos}
          onToggle={vi.fn()}
          onDelete={vi.fn()}
          onEdit={vi.fn()}
          onReorder={vi.fn()}
        />
      </I18nextProvider>
    );

    expect(screen.getByText('할 일 1')).toBeInTheDocument();
    expect(screen.getByText('📅 2025-06-01')).toBeInTheDocument();
    expect(screen.getByText(/우선순위: 보통|Priority: Medium/)).toBeInTheDocument();
  });

  it('calls onToggle when clicking the todo', () => {
    const onToggle = vi.fn();
    render(
      <I18nextProvider i18n={i18n}>
        <TodoList
          todos={baseTodos}
          onToggle={onToggle}
          onDelete={vi.fn()}
          onEdit={vi.fn()}
          onReorder={vi.fn()}
        />
      </I18nextProvider>
    );

    fireEvent.click(screen.getByText('할 일 1'));
    expect(onToggle).toHaveBeenCalledWith('1');
  });

  it('calls onDelete when delete button clicked', () => {
    const onDelete = vi.fn();
    render(
      <I18nextProvider i18n={i18n}>
        <TodoList
          todos={baseTodos}
          onToggle={vi.fn()}
          onDelete={onDelete}
          onEdit={vi.fn()}
          onReorder={vi.fn()}
        />
      </I18nextProvider>
    );

    fireEvent.click(screen.getByText(/삭제|Delete/));
    expect(onDelete).toHaveBeenCalledWith('1');
  });
});