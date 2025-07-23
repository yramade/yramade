import { useEffect, useState } from 'react';
import { useNavigate } from 'react-router-dom';

import { CardRankMap, MockCards, BotMockCards } from '../constants/game';

import ActionButtons from '../components/ActionButtons';
import MyCards from '../components/MyCards';
import SelectionArea from '../components/SelectionArea';
import TurnHistory from '../components/TurnHistory';
import RulePanel from '../components/RulesPanel';

export type Card = { id: string; label: string };
type TurnRecord = {
  turn: number;
  player: 'user' | 'bot';
  card: Card;
};

export default function Game() {
  const [nickname, setNickname] = useState('');
  const navigate = useNavigate();
  const [turn, setTurn] = useState<'user' | 'bot'>('user');
  const [myCards, setMyCards] = useState(MockCards);
  const [botCards, setBotCards] = useState(BotMockCards);
  const [playedUserCards, setPlayedUserCards] = useState<Card[]>([]);
  const [playedBotCard, setPlayedBotCard] = useState<Card | null>(null);
  const [selectedCards, setSelectedCards] = useState<string[]>([]);
  const [isBotThinking, setIsBotThinking] = useState(false);
  const [turnHistory, setTurnHistory] = useState<TurnRecord[]>([]);
  const [turnCount, setTurnCount] = useState(1);
  const [showRules, setShowRules] = useState(false);
  const [message, setMessage] = useState('');
  const [canEndTurn, setCanEndTurn] = useState(false);

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

  const resetTurnState = () => {
    // 봇 턴 끝난 후에 상태 초기화
    setPlayedUserCards([]);
    setPlayedBotCard(null);
    setCanEndTurn(false);
  };

  const toggleSelectCard = (cardId: string) => {
    setSelectedCards(prev => (prev.includes(cardId) ? prev.filter(id => id !== cardId) : [...prev, cardId]));
  };

  const handlePlayCards = () => {
    if (selectedCards.length === 0) {
      setMessage('카드를 선택하세요!');
      return;
    }

    if (selectedCards.length !== 1) {
      setMessage('카드는 한 장만 낼 수 있습니다.');
      return;
    }

    console.log('고른 카드: ', myCards);
    const selectedCardObj = myCards.find(card => card.id === selectedCards[0]);
    if (!selectedCardObj) return;

    if (!isValidPlay(selectedCardObj)) {
      setMessage('이 카드는 낼 수 없습니다. 더 높은 카드를 선택하세요.');
      return;
    }

    const remainingCards = myCards.filter(card => !selectedCards.includes(card.id));
    const playedCards = myCards.filter(card => selectedCards.includes(card.id));
    setMessage('');
    setCanEndTurn(true);
    setMyCards(remainingCards);
    setPlayedUserCards(playedCards); // UI에 표시
    setSelectedCards([]);
    setTurnHistory(prev => [...prev, { turn: turnCount, player: 'user', card: selectedCardObj }]);

    console.log('낸 카드: ', playedCards);
    checkWinCondition();
  };

  const handleEndTurn = () => {
    setMessage('');

    if (turn === 'user') {
      setTurn('bot');

      setTimeout(() => {
        runBotTurn();
        setTurn('user');
        resetTurnState();
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
      setTurnHistory(prev => [...prev, { turn: turnCount, player: 'bot', card: selectedCard }]);
      setTurnCount(prev => prev + 1);

      setIsBotThinking(false);
      checkWinCondition();
    }, 1000);
  };

  const endGame = (result: 'win' | 'lose' | 'draw') => {
    navigate('/result', { state: { result } });
  };

  const checkWinCondition = () => {
    if (myCards.length === 0 && botCards.length === 0) {
      setMessage('무승부입니다!');
      endGame('draw');
    } else if (myCards.length === 0) {
      setMessage(`🎉 ${nickname} 님이 이겼습니다! 축하드립니다!`);
      endGame('win');
    } else if (botCards.length === 0) {
      setMessage('😢 컴퓨터가 이겼습니다. 다음엔 꼭 이겨봐요!');
      endGame('lose');
    }
  };

  const getCardValue = (cardId: string) => {
    const value = cardId.slice(0, -1); // '7♣' → '7'
    return CardRankMap.get(value) ?? -1; // 더 빠르고 안정적이며, 존재하지 않는 값(-1)도 안전하게 처리
  };

  const isValidPlay = (card: Card): boolean => {
    // 검증 함수
    if (!playedBotCard && playedUserCards.length === 0) return true; // 첫 턴

    const lastPlayed = playedBotCard?.id || playedUserCards[playedUserCards.length - 1]?.id;

    if (!lastPlayed) return true;

    return getCardValue(card.id) > getCardValue(lastPlayed);
  };

  const groupedHistory = turnHistory.reduce(
    (acc, record) => {
      const existing = acc.find(group => group.turn === record.turn);
      if (existing) {
        existing[record.player] = record.card;
      } else {
        acc.push({ turn: record.turn, [record.player]: record.card });
      }
      return acc;
    },
    [] as { turn: number; user?: Card; bot?: Card }[],
  );

  return (
    <div className="flex min-h-screen flex-col items-center bg-green-100 p-8">
      <h2 className="mb-4 text-2xl font-bold">
        {turn === 'user' ? `${nickname} 님의 턴입니다.` : '컴퓨터의 턴입니다.'}
      </h2>

      <button
        onClick={() => setShowRules(prev => !prev)}
        className="mb-4 rounded bg-yellow-400 px-3 py-1 text-sm text-white hover:bg-yellow-500">
        {showRules ? '룰 숨기기' : '룰 보기'}
      </button>

      {showRules && <RulePanel />}
      {isBotThinking && <p className="mt-4 text-gray-600">컴퓨터가 카드를 고르는 중...</p>}
      <MyCards
        cards={myCards}
        selected={selectedCards}
        onToggle={toggleSelectCard}
      />
      <SelectionArea selected={selectedCards} />
      <ActionButtons
        disablePlay={turn !== 'user'}
        disableEndTurn={turn !== 'user' || !canEndTurn}
        onEndTurn={handleEndTurn}
        onPlay={handlePlayCards}
      />

      {message && <div className="mb-4 rounded bg-red-100 px-4 py-2 text-sm text-red-700 shadow">{message}</div>}

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
          <div className="flex gap-2">
            <div className="rounded border bg-white px-2 py-1 shadow">{playedBotCard.label}</div>
          </div>
        </div>
      )}

      <TurnHistory groupedHistory={groupedHistory} />
    </div>
  );
}
