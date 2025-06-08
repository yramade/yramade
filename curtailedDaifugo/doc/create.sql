-- 사용자 테이블
CREATE TABLE User (
  Id TEXT PRIMARY KEY,
  Nickname TEXT NOT NULL,
  CreatedAt TEXT NOT NULL,
  LastActive TEXT NOT NULL
);

-- 매치 기록 테이블
CREATE TABLE MatchHistory (
  Id TEXT PRIMARY KEY,
  UserId TEXT NOT NULL,
  Mode TEXT NOT NULL,             -- 'local' or 'match'
  Result TEXT NOT NULL,           -- 'win', 'lose', 'draw'
  Opponent TEXT NOT NULL,
  PlayedAt TEXT NOT NULL,
  FOREIGN KEY (UserId) REFERENCES User(Id)
);
