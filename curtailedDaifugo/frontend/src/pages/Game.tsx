import { useEffect, useState } from 'react';
import { useNavigate } from 'react-router-dom';

import ActionButtons from '../components/ActionButtons';
import MyCards from '../components/MyCards';
import SelectionArea from '../components/SelectionArea';

type Card = { id: string; label: string };
const mockCards = [
  { id: '3♠', label: '3♠' },
  { id: '5♥', label: '5♥' },
  { id: '7♣', label: '7♣' },
  { id: 'J♦', label: 'J♦' },
  { id: 'Q♠', label: 'Q♠' },
  { id: '2♣', label: '2♣' },
  { id: 'A♥', label: 'A♥' },
];

const botMockCards = [
  { id: '4♠', label: '4♠' },
  { id: '6♦', label: '6♦' },
  { id: '9♣', label: '9♣' },
  { id: '7♦', label: '7♦' },
  { id: '10♥', label: '10♥' },
  { id: 'Q♥', label: 'Q♥' },
  { id: 'K♠', label: 'K♠' },
];

export default function Game() {
  const [nickname, setNickname] = useState('');
  const navigate = useNavigate();
  const [turn, setTurn] = useState<'user' | 'bot'>('user');
  const [myCards, setMyCards] = useState(mockCards);
  const [botCards, setBotCards] = useState(botMockCards);
  const [selectedCards, setSelectedCards] = useState<string[]>([]);
  const [playedUserCards, setPlayedUserCards] = useState<Card[]>([]);
  const [playedBotCard, setPlayedBotCard] = useState<Card | null>(null);
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

    const remainingCards = myCards.filter(card => !selectedCards.includes(card.id));
    const playedCards = myCards.filter(card => selectedCards.includes(card.id));
    setMyCards(remainingCards);
    setPlayedUserCards(playedCards); // UI에 표시
    window.console.log('낸 카드: ', playedCards);

    setSelectedCards([]);
  };

  const handleEndTurn = () => {
    if (turn === 'user') {
      setTurn('bot');

      setTimeout(() => {
        runBotTurn();
        setTurn('user');

        // 봇 턴 끝난 후에 상태 초기화
        setPlayedUserCards([]);
        setPlayedBotCard(null);
      }, 1000);
    }
  };

  const runBotTurn = () => {
    console.log('컴퓨터의 턴입니다!');
    setIsBotThinking(true);

    setTimeout(() => {
      if (botCards.length === 0) {
        console.log('컴퓨터가 낼 카드가 없습니다.');
        setIsBotThinking(false);
        return;
      }

      const randomIndex = Math.floor(Math.random() * botCards.length);
      const selectedCard = botCards[randomIndex];

      console.log('컴퓨터가 낸 카드: ', selectedCard);
      const remaining = botCards.filter((_, idx) => idx !== randomIndex);
      setBotCards(remaining);
      setPlayedBotCard(selectedCard); // UI에 표시

      setIsBotThinking(false);
    }, 1000);
  };

  return (
    <div className="flex min-h-screen flex-col items-center bg-green-100 p-8">
      <h2 className="mb-4 text-2xl font-bold">
        {turn === 'user' ? `${nickname} 님의 턴입니다.` : '컴퓨터의 턴입니다.'}
      </h2>

      {isBotThinking && <p className="mt-4 text-gray-600">컴퓨터가 카드를 고르는 중...</p>}
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

      {playedUserCards.length > 0 && (
        <div className="mt-4">
          <h3 className="font-semibold">당신이 낸 카드</h3>
          <div className="flex gap-2">
            {playedUserCards.map(card => (
              <div
                key={card.id}
                className="rounded border bg-white px-2 py-1 shadow">
                {card.label}
              </div>
            ))}
          </div>
        </div>
      )}

      {playedBotCard && (
        <div className="mt-4">
          <h3 className="font-semibold">컴퓨터가 낸 카드</h3>
          <div className="rounded border bg-white px-2 py-1 shadow">{playedBotCard.label}</div>
        </div>
      )}
    </div>
  );
}
