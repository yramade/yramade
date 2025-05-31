import i18n from 'i18next';
import { initReactI18next } from 'react-i18next';

const resources = {
  ko: {
    translation: {
      title: '할 일 목록',
      add: '추가',
      placeholder: '할 일을 입력하세요',
      delete: '삭제',
      clearCompleted: '완료 항목 삭제',
      search: '검색어 입력',
      priority: {
        high: '우선순위: 높음',
        medium: '우선순위: 보통',
        low: '우선순위: 낮음',
        all: '전체 우선순위',
      },
      filter: {
        all: '전체',
        done: '완료만',
        undone: '미완료만',
      },
      empty: '할 일이 없습니다.',
    },
  },
  en: {
    translation: {
      title: 'Todo List',
      add: 'Add',
      placeholder: 'Enter a todo',
      delete: 'Delete',
      clearCompleted: 'Clear completed',
      search: 'Search...',
      priority: {
        high: 'Priority: High',
        medium: 'Priority: Medium',
        low: 'Priority: Low',
        all: 'All Priorities',
      },
      filter: {
        all: 'All',
        done: 'Completed',
        undone: 'Incomplete',
      },
      empty: 'No todos yet.',
    },
  },
};

i18n.use(initReactI18next).init({
  resources,
  lng: 'ko', // 초기 언어
  fallbackLng: 'en',
  interpolation: {
    escapeValue: false,
  },
});

export default i18n;
