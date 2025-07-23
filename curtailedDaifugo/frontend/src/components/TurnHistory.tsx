import type { Card } from '../pages/Game';

type TurnRecordProps = {
  groupedHistory: {
    turn: number;
    user?: Card;
    bot?: Card;
  }[];
};

export default function TurnHistory({ groupedHistory }: TurnRecordProps) {
  if (groupedHistory.length === 0) return null;

  return (
    <div className="mt-6 w-full max-w-md">
      <h3 className="mb-2 text-lg font-semibold">턴 기록</h3>
      <ul className="space-y-3 text-sm">
        {groupedHistory.map(group => (
          <li
            key={group.turn}
            className="rounded bg-white p-3 shadow-sm">
            <p className="font-bold">[턴 {group.turn}]</p>
            <p>당신: {group.user?.label ?? '-'}</p>
            <p>컴퓨터: {group.bot?.label ?? '-'}</p>
          </li>
        ))}
      </ul>
    </div>
  );
}
