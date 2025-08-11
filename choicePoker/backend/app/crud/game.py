from sqlalchemy.orm import Session
from app.models.game import Game
from datetime import datetime
from typing import Optional
from utils.cards import generate_deck, generate_hand
from schemas.game import Game

# 게임 시작
def start_game(db: Session, data: Game) -> Game:
  deck = generate_deck()
  user_card = generate_hand(deck, 5)

  # 중복 카드 제거
  for card in user_card:
    deck.remove(card)

  ai_card = generate_hand(deck, 5)
  
  new_game = Game(
    user_name=data.user_name,
    player_cards=data.player_cards,
    ai_cards=ai_card,
    exchange_cards=0
  )
  db.add(new_game)
  db.commit()
  db.refresh(new_game)
  return new_game

# 게임 정보 수정
def update_game(db: Session, data: Game) -> Optional[Game]:
  game = db.query(Game).filter(Game.id == data.id).first()
  if game:
    game.user_name=data.user_name,
    game.player_cards=data.player_cards,
    game.ai_cards=data.ai_cards,
    game.player_final_cards=data.player_final_cards,
    game.ai_final_cards=data.ai_final_cards,
    game.player_hand_rank=data.player_hand_rank,
    game.ai_hand_rank=data.ai_hand_rank,
    game.choice=data.choice,
    game.choice_by=data.choice_by,
    game.winner=data.winner,
    game.player_dice=data.player_dice,
    game.ai_dice=data.ai_dice
    db.commit()
    db.refresh(game)
  return game

# 게임 정보 조회
def get_game(db: Session, game_id: int) -> Optional[Game]:
  return db.query(Game).filter(Game.id == game_id).first()  

# 사용자 이름으로 게임 조회
def get_game_by_user(db: Session, user_name: str) -> Optional[Game]:
  return db.query(Game).filter(Game.user_name == user_name).first() 

# 게임 삭제 
def delete_game(db: Session, game_id: int) -> Optional[Game]:
  game = db.query(Game).filter(Game.id == game_id).first()
  if game:
    db.delete(game)
    db.commit()
  return game