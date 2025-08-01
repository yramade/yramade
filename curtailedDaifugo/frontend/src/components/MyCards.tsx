interface Card {
  id: string;
  label: string;
}

interface Props {
  cards: Card[];
  selected: string;
  onToggle: (id: string) => void;
}

export default function MyCards({ cards, selected, onToggle }: Props) {
  return (
    <div className="mb-4 w-full max-w-5xl rounded bg-white p-4 shadow">
      <p className="text-center font-semibold text-gray-700">내 카드</p>
      <div className="mt-2 flex flex-wrap justify-center gap-2">
        {cards.map(card => {
          const isSelected = selected === card.id;
          return (
            <div
              key={card.id}
              onClick={() => onToggle(card.id)}
              className={`flex h-16 w-12 cursor-pointer items-center justify-center rounded border text-lg font-bold shadow transition ${isSelected ? 'border-blue-500 ring-2 ring-blue-400' : 'border-gray-400 bg-white'}`}>
              {card.label}
            </div>
          );
        })}
      </div>
    </div>
  );
}
