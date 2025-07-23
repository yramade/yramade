export default function RulePanel() {
  return (
    <div className="mb-6 w-full max-w-md rounded bg-white p-4 shadow">
      <h3 className="mb-2 text-lg font-semibold">게임 규칙</h3>
      <ul className="list-disc pl-5 text-sm leading-relaxed text-gray-700">
        <li>당신과 컴퓨터가 번갈아 가며 카드를 냅니다.</li>
        <li>자신의 턴에는 반드시 한 장의 카드만 낼 수 있습니다.</li>
        <li>가장 최근에 낸 카드보다 더 높은 숫자의 카드만 낼 수 있습니다.</li>
        <li>카드를 모두 먼저 내면 승리합니다.</li>
      </ul>
    </div>
  );
}
