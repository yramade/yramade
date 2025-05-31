import { useState } from 'react';
import type { Todo } from '../types/todo';

import {
  DndContext,
  closestCenter,
  PointerSensor,
  useSensor,
  useSensors,
} from '@dnd-kit/core';
import {
  arrayMove,
  SortableContext,
  verticalListSortingStrategy,
  useSortable,
} from '@dnd-kit/sortable';
import { CSS } from '@dnd-kit/utilities';
import { GripVertical } from 'lucide-react';

type Props = {
  todos: Todo[];
  onToggle: (id: string) => void;
  onDelete: (id: string) => void;
  onEdit: (id: string, newText: string) => void;
  onReorder: (newTodos: Todo[]) => void;
};

function SortableItem({
  todo,
  onToggle,
  onDelete,
  onEdit,
  isEditing,
  setEditId,
  setEditText,
  editText,
  handleEditSubmit,
}: {
  todo: Todo;
  onToggle: (id: string) => void;
  onDelete: (id: string) => void;
  onEdit: (id: string, text: string) => void;
  isEditing: boolean;
  setEditId: (id: string | null) => void;
  setEditText: (text: string) => void;
  editText: string;
  handleEditSubmit: (id: string) => void;
}) {
  const { attributes, listeners, setNodeRef, transform, transition } = useSortable({
    id: todo.id,
  });

  const style = {
    transform: CSS.Transform.toString(transform),
    transition,
  };

  return (
    <li
      ref={setNodeRef}
      style={style}
      {...attributes}
      className="flex flex-col gap-1 p-3 bg-gray-100 rounded-lg shadow-sm"
    >
      <div className="flex justify-between items-center">
        <div className="flex items-center flex-1">
          {isEditing ? (
            <input
              value={editText}
              onChange={(e) => setEditText(e.target.value)}
              onBlur={() => handleEditSubmit(todo.id)}
              onKeyDown={(e) => e.key === 'Enter' && handleEditSubmit(todo.id)}
              autoFocus
              className="flex-1 mr-4 p-1 border rounded"
            />
          ) : (
            <span
              onClick={() => onToggle(todo.id)}
              onDoubleClick={() => {
                setEditId(todo.id);
                setEditText(todo.text);
              }}
              className={`cursor-pointer flex-1 ${
                todo.completed ? 'line-through text-gray-400' : ''
              }`}
            >
              {todo.text}
            </span>
          )}
          <span {...listeners} className="cursor-grab ml-2 text-gray-400 hover:text-gray-600">
            <GripVertical size={16} />
          </span>
        </div>

        <button
          onClick={() => onDelete(todo.id)}
          className="ml-4 text-red-500 hover:text-red-700 transition"
        >
          삭제
        </button>
      </div>

      <div className="text-sm text-gray-500 flex justify-between items-center">
        {todo.dueDate && <span>📅 {todo.dueDate}</span>}
        {todo.priority && (
          <span
            className={`font-semibold ${
              todo.priority === 'high'
                ? 'text-red-500'
                : todo.priority === 'medium'
                ? 'text-yellow-500'
                : 'text-green-500'
            }`}
          >
            {todo.priority === 'high'
              ? '우선순위: 높음'
              : todo.priority === 'medium'
              ? '우선순위: 보통'
              : '우선순위: 낮음'}
          </span>
        )}
      </div>
    </li>
  );
}

export default function TodoList({
  todos,
  onToggle,
  onDelete,
  onEdit,
  onReorder,
}: Props) {
  const [editId, setEditId] = useState<string | null>(null);
  const [editText, setEditText] = useState('');

  const sensors = useSensors(useSensor(PointerSensor));

  const handleEditSubmit = (id: string) => {
    if (editText.trim()) onEdit(id, editText.trim());
    setEditId(null);
  };

  const handleDragEnd = (event: any) => {
    const { active, over } = event;
    if (!over || active.id === over.id) return;

    const oldIndex = todos.findIndex((todo) => todo.id === active.id);
    const newIndex = todos.findIndex((todo) => todo.id === over.id);
    const newTodos = arrayMove(todos, oldIndex, newIndex);
    onReorder(newTodos);
  };

  if (todos.length === 0) {
    return <p className="text-gray-500 text-center">할 일이 없습니다.</p>;
  }

  return (
    <DndContext sensors={sensors} collisionDetection={closestCenter} onDragEnd={handleDragEnd}>
      <SortableContext items={todos.map((todo) => todo.id)} strategy={verticalListSortingStrategy}>
        <ul className="space-y-2">
          {todos.map((todo) => (
            <SortableItem
              key={todo.id}
              todo={todo}
              onToggle={onToggle}
              onDelete={onDelete}
              onEdit={onEdit}
              isEditing={editId === todo.id}
              setEditId={setEditId}
              setEditText={setEditText}
              editText={editText}
              handleEditSubmit={handleEditSubmit}
            />
          ))}
        </ul>
      </SortableContext>
    </DndContext>
  );
}
