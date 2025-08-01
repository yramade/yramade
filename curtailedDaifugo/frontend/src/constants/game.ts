import type { Card } from '../pages/Game';
import Utils from '../lib/Utils';

// 카드 문양 배열
const CardSuits: string[] = ['♠', '♥', '♣', '♦'];
export const CardRankList = ['3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A', '2'];
export const CardRankMap = new Map<string, number>([
  ['3', 3],
  ['4', 4],
  ['5', 5],
  ['6', 6],
  ['7', 7],
  ['8', 8],
  ['9', 9],
  ['10', 10],
  ['J', 11],
  ['Q', 12],
  ['K', 13],
  ['A', 14],
  ['2', 15],
]);

// 모든 카드를 생성하는 함수
const generateAllCards = (): Card[] => {
  const allCards: Card[] = [];

  CardRankList.forEach(rank => {
    CardSuits.forEach(suit => {
      const cardId = `${rank}${suit}`;
      allCards.push({
        id: cardId,
        label: cardId,
      });
    });
  });

  return allCards;
};

// CardRankMap을 활용한 정렬 함수
const sortCardsByRank = (cards: Card[]): Card[] => {
  return cards.sort((a, b) => {
    // 카드 ID에서 랭크 추출
    const getRank = (cardId: string): string => {
      return cardId.replace(/[♠♥♣♦]/g, '');
    };

    const rankA = getRank(a.id);
    const rankB = getRank(b.id);

    // CardRankMap에서 값을 가져와 비교
    const valueA = CardRankMap.get(rankA) || 0;
    const valueB = CardRankMap.get(rankB) || 0;

    return valueA - valueB;
  });
};

export const ShuffleCards = (userCount: number = 7, botCount: number = 7): { userCards: Card[]; botCards: Card[] } => {
  const allCards = generateAllCards();
  const shuffledCards = Utils.shuffleArray(allCards);

  const userCards = sortCardsByRank(shuffledCards.slice(0, userCount));
  const botCards = sortCardsByRank(shuffledCards.slice(userCount, userCount + botCount));

  return { userCards, botCards };
};
