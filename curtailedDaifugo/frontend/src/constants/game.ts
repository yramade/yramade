import type { Card } from '../pages/Game';

export const CardRankList = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A'];
export const CardRankMap = new Map(
  ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A'].map((rank, idx) => [rank, idx]),
);

export const MockCards = [
  { id: '3♠', label: '3♠' },
  { id: '5♥', label: '5♥' },
  { id: '7♣', label: '7♣' },
  { id: 'J♦', label: 'J♦' },
  { id: 'Q♠', label: 'Q♠' },
  { id: '2♣', label: '2♣' },
  { id: 'A♥', label: 'A♥' },
];

export const BotMockCards = [
  { id: '4♠', label: '4♠' },
  { id: '6♦', label: '6♦' },
  { id: '9♣', label: '9♣' },
  { id: '7♦', label: '7♦' },
  { id: '10♥', label: '10♥' },
  { id: 'Q♥', label: 'Q♥' },
  { id: 'K♠', label: 'K♠' },
];
