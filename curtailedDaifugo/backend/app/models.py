from sqlmodel import SQLModel, Field, Relationship
from typing import Optional, List
from datetime import datetime
import uuid

class User(SQLModel, table = True):
  class Config:
    allow_population_by_field_name = True
    populate_by_name= True

  id: str = Field(default_factory=lambda: str(uuid.uuid4()), primary_key = True, alias="Id")
  nickname: str = Field(alias="Nickname")
  createdAt: datetime = Field(default_factory=datetime.now, alias="CreatedAt")
  lastActive: datetime = Field(default_factory=datetime.now, alias="LastActive")

  mathHistory: List["MatchHistory"] = Relationship(back_populates="user")

class MatchHistory(SQLModel, table = True):
  class Config:
    allow_population_by_field_name  = True
    populate_by_name= True

  id: str = Field(default_factory=lambda: str(uuid.uuid4()), primary_key = True, alias="Id")
  userId: str = Field(foreign_key="User.Id", alias="UserId")
  mode: str = Field(alias="Mode") # 'Local' 또는 'Match'
  result: str = Field(alias="Result") # 'win', 'lose' ,'draw'
  opponent: str = Field(alias="Opponent")
  playedAt: datetime = Field(default_factory=datetime.now, alias="PlayedAt")

  user: Optional["User"] = Relationship(back_populates="matchHistory")