from fastapi import APIRouter, Depends, HTTPException
from pydantic import BaseModel
from sqlmodel import Session
from datetime import datetime
from threading import Thread
import random, time

from app.database import getSesstion
from app.models import MatchHistory

router = APIRouter()

# 간단한 카드 우선순위 세트
CARD_ORDER = [ "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "1", "2", "JOKER"]
CARD_VALUES = { card: i for i, card in enumerate(CARD_ORDER)}
SESSION_TIMEOUT_SECONDS = 300 # 5분
activeGames = {}

class PlayCardRequest(BaseModel):
  userId: str
  card: str

class PassRequest(BaseModel):
  userId: str

# 게임 시작
@router.post("/game/startLocal")
def startLocalGame(userId: str, session: Session = Depends(getSesstion)):
  if userId in activeGames:
    raise HTTPException(status_code=404, detail="이미 진행 중인 게임이 있습니다.")
  
  deck = CARD_ORDER.copy() * 2 # 더블 덱
  deck.remove("JOKER") # JOKER는 1장만
  random.shuffle(deck)

  userHand = random.sample(deck, 5)
  for c in userHand:
    deck.remove(c)
  botHand = random.sample(deck, 5)

  activeGames[userId] = {
    "hand": userHand,
    "botHand": botHand,
    "lastPlayed": None,
    "turn": True,
    "finished": False,
    "lastActive": datetime.now()
  }

  return {
    "message": "게임이 시작되었습니다.",
    "yourHand": userHand
  }


@router.post("game/play")
def playCard(payload : PlayCardRequest, session: Session = Depends(getSesstion)):
  userId = payload.userId
  card = payload.card.upper()

  if userId not in activeGames:
    raise HTTPException(status_code=404, detail="진행 중인 게임이 없습니다.")
  
  game = activeGames[userId]
  game["lastActive"] = datetime.now()

  if game["finished"]:
    raise HTTPException(status_code=400, detail="게임이 이미 종료되었습니다.")
  
  if not game["turn"]:
    raise HTTPException(status_code=400, detail="지금은 당신의 턴이 아닙니다.")
  
  if card not in game["hand"]:
    raise HTTPException(status_code=400, detail="해당 카드는 당신의 손패에 없습니다.")
  
  last = game["lastPlayed"]

  # 조커 예외 처리
  if last == "JOKER":
    if card != "3":
      raise HTTPException(status_code=400, detail="조커 이후에는 '3'만 낼 수 있습니다.")
  elif last and CARD_VALUES[card] <= CARD_VALUES[last]:
    raise HTTPException(status_code=400, detail=f"{last}보다 더 높은 카드를 내야 합니다.")
  
  # 정상 진행
  game["hand"].remove(card)
  game["lastPlayed"] = card
  game["turn"] = False # 다음 턴은 봇

  # 게임 종료 확인
  if len(game["hand"]) == 0:
    if not game["finished"]:
      game["finished"] = True
      saveMatchResult(userId, "win", session)
    return {
      "message": f"당신이 '{card}'를 내고 게임에서 승리했습니다!",
      "status": "win"
    }
  
  return {
    "message": f"'{card}'를 냈습니다. 컴퓨터의 턴입니다.",
    "yourHand": game["hand"],
    "lastPlayed": game["lastPlayed"]
  }


@router.post("/game/pass")
def passTurn(payload: PassRequest, session: Session = Depends(getSesstion)):
  userId = payload.userId

  if userId not in activeGames:
    raise HTTPException(status_code=404, detail="진행 중인 게임이 없습니다.")
  
  game = activeGames[userId]
  game["lastActive"] = datetime.now()

  if game["finished"]:
    raise HTTPException(status_code=400, detail="게임이 이미 종료되었습니다.")
  
  if not game["turn"]:
    raise HTTPException(status_code=400, detail="지금은 당신의 턴이 아닙니다.")
  
  # 턴 넘기기
  game["turn"] = False # 봇의 턴으로 전환

  return {
    "message": "당신이 패스했습니다. 컴퓨터의 턴입니다.",
    "lastPlayed": game["lastPlayed"]
  }


def autoPlayBot(userId: str, session: Session = Depends(getSesstion)):
  game = activeGames[userId]
  game["lastActive"] = datetime.now()
  botHand = game["botHand"]
  last = game["lastPlayed"]

  # 가능한 카드 찾기
  validCards = []

  for card in botHand:
    if last == "JOKER" and card == "3":
      validCards.append(card)
    elif last and CARD_VALUES[card] > CARD_VALUES[last]:
      validCards.append(card)
    elif last is None:
      validCards.append(card)
  
  if validCards:
    # 가장 낮은 카드로 내기
    validCards.sort(key=lambda x: CARD_VALUES[x])
    chosen = validCards[0]
    botHand.remove(chosen)
    game["lastPlayed"] = chosen
    game["turn"] = True

    # 게임 종료 체크
    if len(botHand) == 0:
      if not game["finished"]:
        game["finished"] = True
        saveMatchResult(userId, "lose", session)
      return {
        "message": f"컴퓨터가 '{chosen}'를 내고 승리했습니다!",
        "botCard": chosen,
        "status": "lose"
      }
    
    return {
      "message": f"컴퓨터가 '{chosen}'를 냈습니다. 당신의 턴입니다.",
      "botCard": chosen,
      "turn": "you"
    }
  else:
    # 봇이 패스
    game["turn"] = True
    return {
      "message": "컴퓨터가 패스했습니다. 당신의 턴입니다.",
      "botCard": None,
      "turn": "you"
    }
  

@router.get("/game/status/{userId}")
def getGameStatus(userId: str, session: Session = Depends(getSesstion)):
  if userId not in activeGames:
    raise HTTPException(status_code=404, detail="진행 중인 게임이 없습니다.")
  
  game = activeGames[userId]
  game["lastActive"] = datetime.now()

  return {
    "yourHand": game["hand"],
    "yourCardsLeft": len(game["hand"]),
    "botCardLeft": len(game["botHand"]),
    "lastPlayed": game["lastPlayed"],
    "yourTurn": game["turn"],
    "finished": game["finished"]
  }


def saveMatchResult(userId: str, result: str, session: Session):
  match = MatchHistory.model_construct(
    userId = userId,
    mode = "local",
    result = result,
    opponent = "bot",
    playedAt = datetime.now()
  )
  match.model_dump(by_alias=True)
  session.add(match)
  session.commit()


def cleanExpiredSessions():
  while True:
    time.sleep(60) # 1분마다 검사
    now = datetime.now()
    expired = []

    for userId, game in list(activeGames.items()):
      last = game.get("lastActive", now)
      if (now - last).total_seconds() > SESSION_TIMEOUT_SECONDS:
        expired.append(userId)

    for userId in expired:
      print(f"[세션 만료] {userId}의 게임 세션이 제거되었습니다.")
      del activeGames[userId]