import { CardRankList } from '../constants/game';

export default function RulePanel() {
  return (
    <div className="mb-6 w-full max-w-5xl rounded bg-white p-4 shadow">
      <h3 className="mb-2 text-lg font-semibold">게임 규칙</h3>
      <ul className="list-disc text-sm leading-relaxed text-gray-700">
        <li className="list-none text-center">
          <div className="relative my-2 inline-block rounded border border-gray-400 p-3">
            <span className="absolute top-[-10px] left-1/2 -translate-x-8 transform bg-white px-1.5 font-bold text-blue-700">
              카드 순서
            </span>
            <div className="mt-2 mb-3 flex flex-wrap items-center gap-2">
              {CardRankList.map((rank, idx) => (
                <>
                  <span
                    key={rank}
                    className="flex h-14 w-10 cursor-pointer items-center justify-center rounded border border-gray-300 text-lg font-bold shadow">
                    {rank}
                  </span>
                  {idx < CardRankList.length - 1 && (
                    <span
                      key={`rank-${idx}`}
                      className="text-lg font-bold">
                      {'<'}
                    </span>
                  )}
                </>
              ))}
            </div>
          </div>
        </li>
        <li className="ml-5">당신과 컴퓨터가 번갈아 가며 카드를 냅니다.</li>
        <li className="ml-5">자신의 턴에는 반드시 한 장의 카드만 낼 수 있습니다.</li>
        <li className="ml-5">마크에 상관없이 가장 최근에 낸 카드보다 더 높은 숫자의 카드를 냅니다.</li>
        <li className="ml-5">카드를 모두 먼저 내면 승리합니다.</li>
        <li className="ml-5">낼 수 없는 카드만 가진 경우 턴을 넘길 수 있습니다.</li>
      </ul>
    </div>
  );
}
