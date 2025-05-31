import { describe, it, expect, vi } from 'vitest';
import { render, screen, fireEvent } from '@testing-library/react';
import TodoInput from '../components/TodoInput';
import { I18nextProvider } from 'react-i18next';
import i18n from '../i18n';

describe('TodoInput', () => {
  it('submits new todo with all fields and resets inputs', () => {
    const mockOnAdd = vi.fn();
    render(
      <I18nextProvider i18n={i18n}>
        <TodoInput onAdd={mockOnAdd} />
      </I18nextProvider>
    );

    const textInput = screen.getByPlaceholderText(/입력|enter/i);
    const dateInput = screen.getByLabelText(/date/i) || screen.getByDisplayValue('');
    const prioritySelect = screen.getByDisplayValue(/보통|Medium/i);
    const addButton = screen.getByRole('button');

    fireEvent.change(textInput, { target: { value: '테스트 할 일' } });
    fireEvent.change(dateInput, { target: { value: '2025-06-01' } });
    fireEvent.change(prioritySelect, { target: { value: 'high' } });
    fireEvent.click(addButton);

    expect(mockOnAdd).toHaveBeenCalledWith({
      text: '테스트 할 일',
      dueDate: '2025-06-01',
      priority: 'high',
    });

    expect(textInput).toHaveValue('');
    expect(dateInput).toHaveValue('');
    expect(prioritySelect).toHaveValue('medium');
  });

  it('does not submit empty todo', () => {
    const mockOnAdd = vi.fn();
    render(
      <I18nextProvider i18n={i18n}>
        <TodoInput onAdd={mockOnAdd} />
      </I18nextProvider>
    );

    const addButton = screen.getByRole('button');
    fireEvent.click(addButton);

    expect(mockOnAdd).not.toHaveBeenCalled();
  });
});
