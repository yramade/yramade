from sqlalchemy.orm import Session
from app.models.game import Game
from datetime import datetime
from typing import Optional

Class GameInfo:
  id: int
  user_name: str
  player_cards: str
  ai_cards: str
  player_final_cards: Optional[str] = None
  ai_final_cards: Optional[str] = None
  player_hand_rank: Optional[str] = None
  ai_hand_rank: Optional[str] = None
  choice: Optional[str] = None
  choice_by: Optional[str] = None
  winner: Optional[str] = None
  player_dice: Optional[int] = None
  ai_dice: Optional[int] = None
  created_at: datetime

# 게임 시작
def start_game(db: Session, game: GameInfo) -> Game:
  new_game = Game(
    user_name=game.user_name,
    player_cards=game.player_cards,
    ai_cards=game.ai_cards
  )
  db.add(new_game)
  db.commit()
  db.refresh(new_game)
  return new_game

# 게임 정보 수정
def update_game(db: Session, data: GameInfo) -> Optional[Game]:
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