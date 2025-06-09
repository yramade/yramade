import { useEffect, useState } from 'react';
import { useNavigate } from 'react-router-dom';

export default function Game() {
  const [nickname, setNickname] = useState('');
  const navigate = useNavigate();

  useEffect(() => {
    const storedName = localStorage.getItem('nickname');
    if (!storedName) {
      navigate('/');
    } else {
      setNickname(storedName);
    }
  }, [navigate]);

  return (
    <div className="flex min-h-screen flex-col items-center bg-green-100 p-8">
      <h2 className="mb-4 text-2xl font-bold">{nickname} 님의 턴입니다.</h2>

      <div className="mb-4 w-full max-w-2xl rounded bg-white p-4 shadow">
        <p className="text-center font-semibold text-gray-700">내 카드</p>
        {/* TODO: 카드 목록 컴포넌트 */}
      </div>

      <div className="mb-4 w-full max-w-2xl rounded bg-white p-4 shadow">
        <p className="text-center font-semibold text-gray-700">선택 영역</p>
        {/* TODO: 선택된 카드 / 드롭 영역 */}
      </div>

      <div className="flex gap-4">
        <button className="rounded bg-gray-400 px-4 py-2 text-white hover:bg-gray-500">턴 넘기기</button>
        <button className="rounded bg-blue-500 px-4 py-2 text-white hover:bg-blue-600">카드 내기</button>
      </div>
    </div>
  );
}
