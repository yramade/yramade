import { useEffect, useState } from 'react';
import { useNavigate } from 'react-router-dom';

import { CardRankMap, ShuffleCards } from '../constants/game';

import MyCards from '../components/MyCards';
import RulePanel from '../components/RulesPanel';
import TurnHistory from '../components/TurnHistory';
import ActionButtons from '../components/ActionButtons';
import SelectionArea from '../components/SelectionArea';

export type Card = { id: string; label: string };
export type TurnRecordGroup = {
  turn: number;
  user?: Card | null;
  bot?: Card | null;
};

export default function Game() {
  const navigate = useNavigate();
  const [message, setMessage] = useState('');
  const [nickname, setNickname] = useState('');
  const [turnCount, setTurnCount] = useState(1);
  const [showRules, setShowRules] = useState(false);
  const [botHands, setBotHands] = useState<Card[]>([]);
  const [userHands, setUserHands] = useState<Card[]>([]);
  const [turn, setTurn] = useState<'user' | 'bot'>('user');
  const [isBotThinking, setIsBotThinking] = useState(false);
  const [selectingCard, setSelectingCard] = useState<string>('');
  const [turnHistory, setTurnHistory] = useState<TurnRecordGroup[]>([]);
  const [botSelectedCard, setBotSelectedCard] = useState<Card | null>();
  const [userSelectedCard, setUserSelectedCard] = useState<Card | null>();

  const toggleSelectCard = (cardId: string) => {
    setSelectingCard(prev => (prev.length > 0 && prev !== cardId ? cardId : prev === cardId ? '' : cardId));
  };

  const getCardValue = (cardId: string) => {
    const value = cardId.replace(/[^0-9JQKA]/g, '');
    const rank = CardRankMap.get(value.toUpperCase());
    if (rank === undefined) {
      console.error(`랭크 변환 실패: ${cardId} → ${value}`);
      return -1;
    }
    return rank;
  };

  const isValidPlay = (card: Card): boolean => {
    if (turn === 'user') {
      // 유저 턴: 반드시 컴퓨터가 방금 낸 카드보다 커야 함
      if (!botSelectedCard) return true;
      return getCardValue(card.id) > getCardValue(botSelectedCard.id);
    } else {
      // 컴퓨터 턴: 반드시 유저가 방금 낸 카드보다 커야 함
      if (!userSelectedCard) return true;
      return getCardValue(card.id) > getCardValue(userSelectedCard.id);
    }
  };

  const endGame = (result: 'win' | 'lose' | 'draw') => {
    navigate('/result', {
      state: {
        result,
        turnHistory,
        nickname: nickname,
        userRemainingCards: userHands,
        botRemainingCards: botHands,
      },
    });
  };

  const checkWinCondition = () => {
    if (userHands.length === 0 && botHands.length === 0) {
      setMessage('무승부입니다!');
      return 'draw';
    } else if (userHands.length === 0) {
      setMessage(`🎉 ${nickname} 님이 이겼습니다! 축하드립니다!`);
      return 'win';
    } else if (botHands.length === 0) {
      setMessage('😢 컴퓨터가 이겼습니다. 다음엔 꼭 이겨봐요!');
      return 'lose';
    } else {
      return null;
    }
  };

  const reportHistory = (card: Card | null) => {
    if (turn === 'user') {
      setTurnHistory(prev => {
        const updated = prev.map(t => (t.turn === turnCount ? { ...t, user: card } : t));
        return updated.some(t => t.turn === turnCount) ? updated : [...prev, { turn: turnCount, user: card }];
      });
    } else {
      setTurnHistory(prev => {
        const existing = prev.find(t => t.turn === turnCount);
        if (existing) {
          return prev.map(t => (t.turn === turnCount ? { ...t, bot: card } : t));
        } else {
          return [...prev, { turn: turnCount, bot: card }];
        }
      });
    }
  };

  const handlePlayCards = () => {
    console.log('사용자의 턴입니다!');
    setMessage('');

    if (!selectingCard) {
      setMessage('카드를 선택하세요!');
      return;
    }

    const currentCard = userHands.find(card => card.id === selectingCard);
    if (!currentCard || !isValidPlay(currentCard)) {
      setMessage('이 카드는 낼 수 없습니다. 더 높은 카드를 선택하세요.');
      return;
    }

    const remainingCards = userHands.filter(card => card.id !== currentCard.id);
    reportHistory(currentCard);
    setUserHands(remainingCards);
    setUserSelectedCard(currentCard);
    console.log('낸 카드: ', currentCard);

    const turnResult = checkWinCondition();
    if (!turnResult) setTurn('bot');
    else endGame(turnResult);
  };

  const runBotTurn = () => {
    console.log('컴퓨터의 턴입니다!');
    setMessage('');
    setIsBotThinking(true);

    setTimeout(() => {
      const validCards = botHands.filter(card => isValidPlay(card));
      if (validCards.length === 0) {
        setMessage('컴퓨터가 낼 수 있는 카드가 없어 턴을 넘깁니다.');
        console.log('컴퓨터가 낼 수 있는 카드가 없습니다.');
        setBotSelectedCard(null);
        reportHistory(null);
        setIsBotThinking(false);
        setTurnCount(prev => prev + 1);
        setTurn('user');
        return;
      }

      const currentCard = validCards[Math.floor(Math.random() * validCards.length)];
      const remainingCards = botHands.filter(card => card.id !== currentCard.id);

      reportHistory(currentCard);
      setBotSelectedCard(currentCard);
      setBotHands(remainingCards);
      setIsBotThinking(false);
      setSelectingCard('');
      setUserSelectedCard(null);

      const turnResult = checkWinCondition();
      if (!turnResult) {
        setTurnCount(prev => prev + 1);
        setTurn('user');
      } else endGame(turnResult);
    }, 1000);
  };

  useEffect(() => {
    const { userCards, botCards } = ShuffleCards(7, 7);
    setUserHands(userCards);
    setBotHands(botCards);
  }, []);

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

  useEffect(() => {
    if (userSelectedCard) {
      setSelectingCard('');
      setBotSelectedCard(null);
    } else if (botSelectedCard) {
      setUserSelectedCard(null);
    }
  }, [userSelectedCard, botSelectedCard]);

  useEffect(() => {
    if (turn === 'user') {
      if (turnCount === 1) return;
      const hasLargerCard = userHands.some(card => isValidPlay(card));
      if (!hasLargerCard) {
        setUserSelectedCard(null);
        setMessage('낼 수 있는 카드가 없어서 자동으로 턴을 넘깁니다.');
        setTimeout(() => {
          setMessage('');
          setTurnCount(prev => prev + 1);
          setTurn('bot');
        }, 800);
        return;
      }
    } else {
      runBotTurn();
    }
  }, [turn]);

  if (!nickname) return null; // 또는 <LoadingSpinner />

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
        cards={userHands}
        selected={selectingCard}
        onToggle={toggleSelectCard}
      />
      <SelectionArea selected={selectingCard} />
      <ActionButtons
        disablePlay={turn !== 'user' || isBotThinking}
        onPlay={handlePlayCards}
        /* disableEndTurn={turn !== 'user' || !canEndTurn}
          onEndTurn={handleEndTurn} */
      />

      {message && <div className="mb-4 rounded bg-red-100 px-4 py-2 text-sm text-red-700 shadow">{message}</div>}

      {userSelectedCard && (
        <div className="mt-4">
          <h3 className="font-semibold">당신이 낸 카드</h3>
          <div className="flex gap-2">
            <div
              key={userSelectedCard.id}
              className="rounded border bg-white px-2 py-1 shadow">
              {userSelectedCard.label}
            </div>
          </div>
        </div>
      )}

      {botSelectedCard && (
        <div className="mt-4">
          <h3 className="font-semibold">컴퓨터가 낸 카드</h3>
          <div className="flex gap-2">
            <div className="rounded border bg-white px-2 py-1 shadow">{botSelectedCard.label}</div>
          </div>
        </div>
      )}

      {turnHistory.length > 0 && <TurnHistory groupedHistory={turnHistory} />}
    </div>
  );
}
