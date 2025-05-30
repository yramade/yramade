import { useState } from "react";
import TodoInput from "./components/TodoInput";
import TodoList from "./components/TodoList";

function App() {
  const [todos, setTodos] = useState<any>([]);

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

  return(
    <div className="max-w-md mx-auto mt-10 p-4 bg-white shadow rounded">
      <h1 className="text-2xl font-bold mb-4 text-center">Todo List</h1>
      <TodoInput addTodo={addTodo} />
      <TodoList todos={todos} />
    </div>
  )
}

export default App;