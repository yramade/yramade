import { use, useState } from 'react';
import { useNavigate } from 'react-router-dom';

export default function Home() {
  const [nickname, setNickname] = useState('');
  const navigate = useNavigate();

  const handleStart = () => {
    if (nickname.trim()) {
      // 닉네임은 나중에 서버에 저장 및 전역 상태로 관리 가능
      localStorage.setItem('nickname', nickname.trim());
      navigate('/game');
    }
  };

  const handleKeyDown = (e: React.KeyboardEvent<HTMLInputElement>) => {
    if (e.key === 'Enter') {
      handleStart();
    }
  };

  return (
    <div className="flex min-h-screen flex-col items-center justify-center bg-gray-100">
      <h1 className="fond-bold mb-8 text-3xl">단축 대부호</h1>
      <input
        type="text"
        value={nickname}
        onKeyDown={handleKeyDown}
        onChange={e => setNickname(e.target.value)}
        placeholder="닉네임을 입력하세요"
        className="mb-4 w-64 rounded-md border border-gray-300 px-4 py-2 focus:ring-2 focus:ring-blue-500 focus:outline-none"
      />
      <button
        onClick={handleStart}
        disabled={!nickname.trim()}
        className={`w-64 rounded-md py-2 font-semibold text-white transition ${
          nickname.trim() ? 'bg-blue-500 hover:bg-blue-600' : 'cursor-not-allowed bg-gray-400'
        }`}>
        게임 시작
      </button>
    </div>
  );
}
