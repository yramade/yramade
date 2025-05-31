// src/__tests__/App.test.tsx
import { describe, it, expect, vi } from 'vitest';
import { render, screen, fireEvent } from '@testing-library/react';
import App from '../App';
import { I18nextProvider } from 'react-i18next';
import i18n from '../i18n';

describe('App integration', () => {
  it('renders app title and language switch works', () => {
    render(
      <I18nextProvider i18n={i18n}>
        <App />
      </I18nextProvider>
    );

    expect(screen.getByText(/할 일 목록|Todo List/)).toBeInTheDocument();

    fireEvent.click(screen.getByText('🇺🇸'));
    expect(screen.getByText('Todo List')).toBeInTheDocument();

    fireEvent.click(screen.getByText('🇰🇷'));
    expect(screen.getByText('할 일 목록')).toBeInTheDocument();
  });

  it('adds and filters todo item with search and priority', () => {
    render(
      <I18nextProvider i18n={i18n}>
        <App />
      </I18nextProvider>
    );

    // 입력 필드 채우기
    fireEvent.change(screen.getByPlaceholderText('할 일을 입력하세요'), {
      target: { value: '공부하기' },
    });
    fireEvent.change(screen.getByDisplayValue(/보통|Medium/), {
      target: { value: 'high' },
    });
    fireEvent.click(screen.getByText(/추가|Add/));

    // 추가 확인
    expect(screen.getByText('공부하기')).toBeInTheDocument();

    // 검색 테스트
    fireEvent.change(screen.getByPlaceholderText('검색어 입력'), {
      target: { value: '공' },
    });
    expect(screen.getByText('공부하기')).toBeInTheDocument();

    fireEvent.change(screen.getByPlaceholderText('검색어 입력'), {
      target: { value: '운동' },
    });
    expect(screen.queryByText('공부하기')).not.toBeInTheDocument();
  });

  it('clears completed todos', () => {
    render(
      <I18nextProvider i18n={i18n}>
        <App />
      </I18nextProvider>
    );

    fireEvent.change(screen.getByPlaceholderText('할 일을 입력하세요'), {
      target: { value: '할 일 테스트' },
    });
    fireEvent.click(screen.getByText(/추가|Add/));

    fireEvent.click(screen.getByText('할 일 테스트'));
    fireEvent.click(screen.getByText(/완료 항목 삭제|Clear completed/));

    expect(screen.queryByText('할 일 테스트')).not.toBeInTheDocument();
  });
});
