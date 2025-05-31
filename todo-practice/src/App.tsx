import { useReducer, useState } from 'react';
import TodoInput from './components/TodoInput';
import TodoList from './components/TodoList';
import { reducer, initialState } from './hooks/reducer';
import type { Todo } from './types/todo';
import { useTranslation } from 'react-i18next';

function App() {
  const [state, dispatch] = useReducer(reducer, initialState);
  const [searchText, setSearchText] = useState('');
  const [filterPriority, setFilterPriority] = useState<'all' | 'high' | 'medium' | 'low'>('all');
  const [showCompleted, setShowCompleted] = useState<'all' | 'done' | 'undone'>('all');

  const { t, i18n } = useTranslation();
  const changeLanguage = (lang: 'ko' | 'en') => i18n.changeLanguage(lang);

  const filteredTodos = state.todos.filter((todo) => {
    const matchesText = todo.text.toLowerCase().includes(searchText.toLowerCase());
    const matchesPriority = filterPriority === 'all' || todo.priority === filterPriority;
    const matchesCompleted =
      showCompleted === 'all' ||
      (showCompleted === 'done' && todo.completed) ||
      (showCompleted === 'undone' && !todo.completed);

    return matchesText && matchesPriority && matchesCompleted;
  });

  return (
    <div className="max-w-xl mx-auto p-4 space-y-4">
      <div className="flex justify-between items-center">
        <h1 className="text-2xl font-bold">{t('title')}</h1>
        <div className="flex gap-2 text-sm">
          <button onClick={() => changeLanguage('ko')}>🇰🇷</button>
          <button onClick={() => changeLanguage('en')}>🇺🇸</button>
        </div>
      </div>

      <TodoInput onAdd={(payload) => dispatch({ type: 'ADD_TODO', payload })} />

      <div className="space-y-2">
        <input
          value={searchText}
          onChange={(e) => setSearchText(e.target.value)}
          placeholder={t('search')}
          className="w-full p-2 border rounded"
        />

        <div className="flex gap-2">
          <select
            value={filterPriority}
            onChange={(e) => setFilterPriority(e.target.value as any)}
            className="w-full p-2 border rounded"
          >
            <option value="all">{t('priority.all')}</option>
            <option value="high">{t('priority.high')}</option>
            <option value="medium">{t('priority.medium')}</option>
            <option value="low">{t('priority.low')}</option>
          </select>

          <select
            value={showCompleted}
            onChange={(e) => setShowCompleted(e.target.value as any)}
            className="w-full p-2 border rounded"
          >
            <option value="all">{t('filter.all')}</option>
            <option value="done">{t('filter.done')}</option>
            <option value="undone">{t('filter.undone')}</option>
          </select>
        </div>
      </div>

      {state.todos.some((t) => t.completed) && (
        <button
          onClick={() => dispatch({ type: 'CLEAR_COMPLETED' })}
          className="w-full bg-red-500 text-white p-2 rounded hover:bg-red-600 transition"
        >
          {t('clearCompleted')}
        </button>
      )}

      <TodoList
        todos={filteredTodos}
        onToggle={(id) => dispatch({ type: 'TOGGLE_TODO', payload: id })}
        onDelete={(id) => dispatch({ type: 'DELETE_TODO', payload: id })}
        onEdit={(id, text) => dispatch({ type: 'EDIT_TODO', payload: { id, text } })}
        onReorder={(newTodos: Todo[]) => dispatch({ type: 'REORDER_TODOS', payload: newTodos })}
      />
    </div>
  );
}

export default App;