import { useLocation, useNavigate } from 'react-router-dom';

export default function Result() {
  const navigate = useNavigate();
  const location = useLocation();
  const result = location.state?.result;

  if (!result) {
    return <p className="mt-10 text-center">결과 정보가 없습니다.</p>;
  }

  return (
    <div className="flex min-h-screen flex-col items-center justify-center bg-yellow-100 p-8">
      <h2 className="mb-6 text-3xl font-bold">
        {result === 'win' && '🎉 당신이 이겼습니다!'}
        {result === 'lose' && '😢 컴퓨터가 이겼습니다.'}
        {result === 'draw' && '🤝 무승부입니다!'}
      </h2>

      <button
        onClick={() => navigate('/')}
        className="mt-4 rounded bg-blue-500 px-4 py-2 text-white hover:bg-blue-600">
        다시 시작하기
      </button>
    </div>
  );
}
