from sqlalchemy import Column, Integer, String, DateTime, func
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()

class Game(Base):
    __tablename__ = "Game"

    id = Column(Integer, primary_key=True, index=True)
    user_name = Column(String(50), unique=True, nullable=False)
    player_cards = Column(String, nullable=False)
    ai_cards = Column(String, nullable=False)
    player_final_cards = Column(String)
    ai_final_cards = Column(String)
    player_hand_rank = Column(String(50))
    ai_hand_rank = Column(String(50))
    choice = Column(String(10), choices=[('strong', 'Strong'), ('weak', 'Weak')])
    choice_by: Column(String(10), choices=[('player', 'Player'), ('ai', 'Computer')])
    winner: Column(String(10), choices=[('player', 'Player'), ('ai', 'Computer'), ('draw', 'Draw')])
    player_dice = Column(Integer)
    ai_dice = Column(Integer)
    created_at = Column(DateTime, server_default=func.now(), nullable=False)


class StartGame(BaseModel):
    id: int
    name: str
    created_at: datetime

# from pydantic import BaseModel
# from datetime import datetime

# class Game(BaseModel):
#     id: AutoField(REQUIRED, primary_key=True)
#     user_name: StringField(REQUIRED, foreign_key=True)
#     player_cards: StringField(REQUIRED)
#     ai_cards: StringField(REQUIRED)
#     player_final_cards: StringField()
#     ai_final_cards: StringField()
#     player_hand_rank: StringField(max_length=50)
#     ai_hand_rank: StringField(max_length=50)
#     choice: StringField(max_length=10, choices=[('strong', 'Strong'), ('weak', 'Weak')])
#     choice_by: StringField(max_length=10, choices=[('player', 'Player'), ('ai', 'Computer')])
#     winner: StringField(max_length=10, choices=[('player', 'Player'), ('ai', 'Computer'), ('draw', 'Draw')])
#     player_dice: IntegerField()
#     ai_dice: IntegerField()
#     created_at: DateTimeField(REQUIRED, format="%Y%m%d%H%M%S", auto_now_add=True)

#     def gameStart(self, userName: str):
#         self.user_name = userName
#         self.created_at = datetime.now()
#         self.player_cards = ""
#         ai_cards = ""
#         return self

#     def exchange(self, cards: str[]):
#         self.player_cards = ','.join(cards)
#         self.ai_cards = ''
#         return self

#     def rollDice(self, player_dice: int, ai_dice: int):