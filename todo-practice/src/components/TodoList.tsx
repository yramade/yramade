function TodoList({ todos, toggleTodo, deleteTodo }: any) {
  if(todos.length === 0){
    return <p className="text-gray-500 text-center">
      할 일이 없습니다.
    </p>
  }

  return(
    <ul className="space-y-2">
      {todos.map((todo: any) => (
        <li key={todo.id} className="border px-3 py-2 rounded shadow-sm">
          <label className="flex items-center gap-2 cursor-pointer">
            <input
              type="checkbox"
              checked={todo.completed}
              onChange={() => toggleTodo(todo.id)}
            />
            <span className={todo.completed ? 'line-through text-gray-400' : ''}>
              {todo.text}
            </span>
          </label>
          <button
            onClick={() => deleteTodo(todo.id)}
            className="text-red-500 hover:text-red-700"
          >
            삭제
          </button>
        </li>
      ))}
    </ul>
  )
}

export default TodoList;