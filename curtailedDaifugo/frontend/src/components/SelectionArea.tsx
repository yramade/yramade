interface Props {
  selected: string;
}

export default function SelectionArea({ selected }: Props) {
  return (
    <div className="mb-4 w-full max-w-5xl rounded bg-white p-4 shadow">
      <p className="text-center font-semibold text-gray-700">선택한 카드</p>
      <div className="flex flex-wrap justify-center gap-2">
        {selected.length === 0 ? (
          <p className="text-gray-500">선택된 카드가 없습니다.</p>
        ) : (
          <div
            key={selected}
            className="flex h-16 w-12 items-center justify-center rounded border border-blue-400 bg-blue-50 text-lg font-bold shadow">
            {selected}
          </div>
        )}
      </div>
    </div>
  );
}
