-- poker 데이터베이스 구조 내보내기
CREATE DATABASE IF NOT EXISTS `poker` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_bin */;
USE `poker`;

-- 👤 사용자 테이블
CREATE TABLE IF NOT EXISTS User (
  id INTEGER NOT NULL AUTO_INCREMENT,        -- 사용자 고유 ID
  nickname VARCHAR(50) NOT NULL,               -- 사용자가 입력한 닉네임
  createdAt DATETIME DEFAULT CURRENT_TIMESTAMP, -- 계정 생성 시각
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

-- 🃏 게임 진행 및 결과 테이블
CREATE TABLE IF NOT EXISTS Game (
  id INTEGER NOT NULL AUTO_INCREMENT,        -- 게임 고유 ID
  userId INTEGER NOT NULL,                     -- 게임을 플레이한 사용자 ID (외래 키)

  playerCards TEXT NOT NULL,                   -- 플레이어 최초 패 (JSON 문자열 예: '["AS", "KD", "9H", ...]')
  aiCards TEXT NOT NULL,                       -- AI 최초 패
  playerFinalCards TEXT NOT NULL,              -- 플레이어 교환 후 최종 패
  aiFinalCards TEXT NOT NULL,                  -- AI 교환 후 최종 패

  playerHandRank VARCHAR(50),                  -- 플레이어 족보 이름 (예: "Straight", "Flush")
  aiHandRank VARCHAR(50),                      -- AI 족보 이름

  choice TEXT CHECK(choice IN ('strong', 'weak')), -- 초이스 결정: 'strong'(강한 패 승) 또는 'weak'(약한 패 승)
  choiceBy TEXT CHECK(choiceBy IN ('player', 'ai')), -- 초이스 선택자: 'player' 또는 'ai'

  winner TEXT CHECK(winner IN ('player', 'ai', 'draw')), -- 승자 정보

  playerDice INTEGER CHECK(playerDice BETWEEN 1 AND 6), -- 플레이어 주사위 결과 (1~6)
  aiDice INTEGER CHECK(aiDice BETWEEN 1 AND 6),         -- AI 주사위 결과

  createdAt DATETIME DEFAULT CURRENT_TIMESTAMP,         -- 게임 생성 시각

  PRIMARY KEY (`id`),
  FOREIGN KEY (userId) REFERENCES User(id)              -- 사용자 테이블 참조
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

-- 📜 게임 진행 로그 테이블 (선택)
CREATE TABLE IF NOT EXISTS GameLog (
  id INTEGER NOT NULL AUTO_INCREMENT,                  -- 로그 고유 ID
  gameId INTEGER NOT NULL,                               -- 연관된 게임 ID

  eventType TEXT CHECK(eventType IN                      -- 이벤트 종류:
    ('deal', 'exchange', 'roll', 'choice', 'showdown')   -- 카드 배분, 교환, 주사위, 초이스, 쇼다운
  ),

  description TEXT,                                      -- 상세 설명 또는 JSON 데이터
  createdAt DATETIME DEFAULT CURRENT_TIMESTAMP,          -- 로그 생성 시각

PRIMARY KEY (`id`),
  FOREIGN KEY (gameId) REFERENCES Game(id)               -- 게임 테이블 참조
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;
