import type { Card } from '../pages/Game';

export type TurnRecordProps = {
  groupedHistory: {
    turn: number;
    user?: Card | null;
    bot?: Card | null;
  }[];
};

export default function TurnHistory({ groupedHistory }: TurnRecordProps) {
  if (groupedHistory.length === 0) return null;

  return (
    <div className="mt-6 w-full max-w-md">
      <h3 className="mb-2 text-lg font-semibold">턴 기록</h3>
      <ul className="space-y-3 text-sm">
        {groupedHistory.map(({ turn, user, bot }) => (
          <li
            key={turn}
            className="rounded bg-white p-3 shadow-sm">
            <p className="font-bold">[{turn}턴]</p>
            <p>당신: {user?.label ?? '없음'}</p>
            <p>컴퓨터: {bot?.label ?? '없음'}</p>
          </li>
        ))}
      </ul>
    </div>
  );
}
