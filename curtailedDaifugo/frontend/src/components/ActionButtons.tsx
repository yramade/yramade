interface Props {
  disablePlay: boolean;
  disableEndTurn?: boolean;
  onPlay: () => void;
  onEndTurn?: () => void;
}

export default function ActionButtons({ onPlay, onEndTurn, disablePlay, disableEndTurn }: Props) {
  return (
    <div className="flex gap-4">
      <button
        onClick={onPlay}
        disabled={disablePlay}
        className="cursor-pointer rounded bg-blue-500 px-4 py-2 text-white hover:bg-blue-600">
        카드 내기
      </button>

      {/* <button
        onClick={onEndTurn}
        disabled={disableEndTurn}
        className="rounded bg-gray-400 px-4 py-2 text-white hover:bg-gray-500">
        턴 넘기기
      </button> */}
    </div>
  );
}
