import { useEffect, useState } from 'react';
import { useNavigate } from 'react-router-dom';

import ActionButtons from '../components/ActionButtons';
import MyCards from '../components/MyCards';
import SelectionArea from '../components/SelectionArea';

const mockCards = [
  { id: '3♠', label: '3♠' },
  { id: '5♥', label: '5♥' },
  { id: '7♣', label: '7♣' },
  { id: 'J♦', label: 'J♦' },
  { id: 'Q♠', label: 'Q♠' },
  { id: '2♣', label: '2♣' },
  { id: 'A♥', label: 'A♥' },
];

export default function Game() {
  const [nickname, setNickname] = useState('');
  const navigate = useNavigate();
  const [selectedCards, setSelectedCards] = useState<string[]>([]);
  const [turn, setTurn] = useState<'user' | 'bot'>('user');
  const [myCards, setMyCards] = useState(mockCards);
  const [isBotThinking, setIsBotThinking] = useState(false);

  useEffect(() => {
    const storedName = localStorage.getItem('nickname');
    if (!storedName) {
      navigate('/');
    } else if (storedName === nickname) {
      return;
    } else {
      setNickname(storedName);
    }
  }, [navigate, nickname]);

  if (!nickname) return null; // 또는 <LoadingSpinner />

  const toggleSelectCard = (cardId: string) => {
    setSelectedCards(prev => (prev.includes(cardId) ? prev.filter(id => id !== cardId) : [...prev, cardId]));
  };

  const handlePlayCards = () => {
    if (selectedCards.length === 0) {
      alert('카드를 선택하세요!');
      return;
    }

    window.console.log('선택된 카드: ', selectedCards);
    // TODO: 서버에 전송 or 상태 갱신 등
  };

  const handleEndTurn = () => {
    if (turn === 'user') {
      setTurn('bot');

      setTimeout(() => {
        runBotTurn();
        setTurn('user');
      }, 1000);
    }
  };

  const runBotTurn = () => {
    console.log('봇의 턴입니다!');
    // 여기에 봇 로직 추가할 예정
    // ex. isBotThinking 상태 추가해서 메시지 표시
  };

  return (
    <div className="flex min-h-screen flex-col items-center bg-green-100 p-8">
      <h2 className="mb-4 text-2xl font-bold">
        {turn === 'user' ? `${nickname} 님의 턴입니다.` : '컴퓨터의 턴입니다.'}
      </h2>

      <MyCards
        cards={myCards}
        selected={selectedCards}
        onToggle={toggleSelectCard}
      />
      <SelectionArea selected={selectedCards} />
      <ActionButtons
        disabled={turn !== 'user'}
        onEndTurn={handleEndTurn}
        onPlay={handlePlayCards}
      />
    </div>
  );
}
