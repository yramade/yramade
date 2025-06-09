interface Props {
  onPlay: () => void;
}

export default function ActionButtons({ onPlay }: Props) {
  return (
    <div className="flex gap-4">
      <button className="rounded bg-gray-400 px-4 py-2 text-white hover:bg-gray-500">턴 넘기기</button>
      <button
        onClick={onPlay}
        className="cursor-pointer rounded bg-blue-500 px-4 py-2 text-white hover:bg-blue-600">
        카드 내기
      </button>
    </div>
  );
}
