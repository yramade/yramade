import { useLocation, useNavigate } from 'react-router-dom';
import type { Card, TurnRecordGroup } from '../pages/Game';

export default function Result() {
  const navigate = useNavigate();
  const location = useLocation();
  const result = location.state?.result as 'win' | 'lose' | 'draw' | undefined;
  const turnHistory = location.state?.turnHistory as TurnRecordGroup[] | undefined;

  if (!result) {
    return <p className="mt-10 text-center">결과 정보가 없습니다.</p>;
  }

  const resultMap = {
    win: {
      emoji: '🏆',
      title: '🎉 당신이 이겼습니다!',
      message: '멋진 플레이였어요! 대부호의 재능이 있군요!',
      bgColor: 'bg-yellow-100',
    },
    lose: {
      emoji: '💀',
      title: '😢 컴퓨터가 이겼습니다.',
      message: '아쉽네요! 다음 판엔 더 전략적으로 도전해보세요.',
      bgColor: 'bg-gray-200',
    },
    draw: {
      emoji: '🤝',
      title: '무승부입니다!',
      message: '균형 잡힌 한 판이었어요. 다음엔 꼭 승리하세요.',
      bgColor: 'bg-blue-100',
    },
  };

  const { title, message, bgColor } = resultMap[result];

  const totalTurns = turnHistory?.length || 0;
  const totalPlays = turnHistory ? turnHistory.reduce((acc, t) => acc + (t.user ? 1 : 0) + (t.bot ? 1 : 0), 0) : 0;

  return (
    <div className={`flex min-h-screen flex-col items-center justify-center ${bgColor} p-8`}>
      <div className="rounded-lg border border-gray-300 bg-white px-10 py-8 shadow-lg">
        <h2 className="mb-4 text-center text-3xl font-bold">{title}</h2>
        <p className="mb-6 text-center text-lg text-gray-700">{message}</p>

        {turnHistory && (
          <div className="mt-6 mb-4 text-center text-sm text-gray-600">
            총 <strong>{totalTurns}</strong>턴 동안 <strong>{totalPlays}</strong>장의 카드로 플레이했습니다.
          </div>
        )}

        <div className="mt-6 flex justify-center gap-4">
          <button
            onClick={() => navigate('/game')}
            className="rounded bg-blue-500 px-6 py-2 text-white shadow transition-colors hover:bg-blue-600">
            게임 다시하기
          </button>

          <button
            onClick={() => navigate('/')}
            className="rounded bg-blue-500 px-6 py-2 text-white shadow transition-colors hover:bg-blue-600">
            메인으로 가기
          </button>
        </div>
      </div>
    </div>
  );
}
