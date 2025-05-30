import { useState } from 'react';

function TodoInput({ addTodo }: any) {
  const [input, setInput] = useState('');

  const handleSubmit = (e: any) => {
    e.preventDefault();
    if(!input.trim()) return;
    addTodo(input);
    setInput('');
  };

  return(
    <form onSubmit={handleSubmit} className='flex gap-2 mb-4'>
      <input
        type='text'
        value={input}
        onChange={(e) => setInput(e.target.value)}
        className='flex-1 border rounded px-3 py-2'
        placeholder='할 일을 입력하세요'
      />
      <button type='submit'
        className='px-4 py-2 bg-blue-500 text-white rounded hover:bg-blue-600'
      >
        추가
      </button>
    </form>
  )

}

export default TodoInput;