interface Card {
  id: string;
  label: string;
}

interface Props {
  cards: Card[];
}

export default function MyCards({ cards }: Props) {
  return (
    <div className="mb-4 w-full max-w-2xl rounded bg-white p-4 shadow">
      <p className="text-center font-semibold text-gray-700">내 카드</p>
      <div className="mt-2 flex flex-wrap justify-center gap-2">
        {cards.map(card => (
          <div
            key={card.id}
            className="flex h-16 w-12 items-center justify-center rounded border border-gray-400 bg-white text-lg font-bold shadow">
            {card.label}
          </div>
        ))}
      </div>
    </div>
  );
}
