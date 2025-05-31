// src/components/TodoInput.tsx
import { useState } from 'react';
import { useTranslation } from 'react-i18next';

type Props = {
  onAdd: (payload: {
    text: string;
    dueDate?: string;
    priority?: 'high' | 'medium' | 'low';
  }) => void;
};

export default function TodoInput({ onAdd }: Props) {
  const [text, setText] = useState('');
  const [dueDate, setDueDate] = useState('');
  const [priority, setPriority] = useState<'high' | 'medium' | 'low'>('medium');
  const { t } = useTranslation();

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (text.trim() === '') return;

    onAdd({
      text: text.trim(),
      dueDate: dueDate || undefined,
      priority,
    });

    setText('');
    setDueDate('');
    setPriority('medium');
  };

  return (
    <form onSubmit={handleSubmit} className="space-y-2">
      <input
        type="text"
        value={text}
        onChange={(e) => setText(e.target.value)}
        placeholder={t('placeholder')}
        className="w-full p-2 border rounded"
      />

      <label htmlFor="dueDate" className="sr-only">
        Due Date
      </label>
      <input
        id="dueDate"
        type="date"
        value={dueDate}
        onChange={(e) => setDueDate(e.target.value)}
        className="w-full p-2 border rounded"
      />

      <select
        value={priority}
        onChange={(e) => setPriority(e.target.value as 'high' | 'medium' | 'low')}
        className="w-full p-2 border rounded"
      >
        <option value="high">{t('priority.high')}</option>
        <option value="medium">{t('priority.medium')}</option>
        <option value="low">{t('priority.low')}</option>
      </select>

      <button
        type="submit"
        className="w-full bg-blue-500 text-white p-2 rounded hover:bg-blue-600 transition"
      >
        {t('add')}
      </button>
    </form>
  );
}