import { useState, useEffect } from "react";
import TodoInput from "./components/TodoInput";
import TodoList from "./components/TodoList";

function App() {
  const [todos, setTodos] = useState<any>([]);
  const [filter, setFilter] = useState('all');  // 'all' | 'completed' | 'incomplete'

  useEffect(() => {
    const savedTodos = localStorage.getItem("todos");
    if(savedTodos){
      setTodos(JSON.parse(savedTodos));
    }
  },[]);

  useEffect(() => {
    localStorage.setItem("todos", JSON.stringify(todos));
  },[todos]);

  const addTodo = (text: string) => {
    const newTodo = {
      id: Date.now(),
      text,
      complete: false
    };
    setTodos([newTodo, ...todos])
  };

  const toggleTodo = (id: string) => {
    setTodos(
      todos.map((todo: any) =>
      todo.id === id ? { ...todo, completed: !todo.completed} : todo)
    )
  };

  const deleteTodo = (id: string) => {
    setTodos(todos.filter((todo: any) => todo.id !== id))
  };

  const filteredTodos = todos.filter((todo: any) => {
    if(filter === 'completed') return todo.completed;
    if(filter === 'incomplete') return !todo.completed;
    return true;
  });

  return(
    <div className="max-w-md mx-auto mt-10 p-4 bg-white shadow rounded">
      <h1 className="text-2xl font-bold mb-4 text-center">Todo List</h1>
      <TodoInput addTodo={addTodo} />
      <div className="flex gap-2 my-4">
        <button
          onClick={() => setFilter('all')}
          className={`px-3 py-1 border rounded ${filter === 'all' ? 'bg-blue-500 text-white' : ''}`}
        >
          전체
        </button>
        <button
          onClick={() => setFilter('completed')}
          className={`px-3 py-1 border rounded ${filter === 'completed' ? 'bg-blue-500 text-white' : ''}`}
        >
          완료
        </button>
        <button
          onClick={() => setFilter('incomplete')}
          className={`px-3 py-1 border rounded ${filter === 'incomplete' ? 'bg-blue-500 text-white' : ''}`}
        >
          미완료
        </button>
      </div>
      <TodoList todos={filteredTodos} toggleTodo={toggleTodo} deleteTodo={deleteTodo}  />
    </div>
  )
}

export default App;