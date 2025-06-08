from sqlmodel import SQLModel, Field, Relationship
from typing import Optional, List
from datetime import datetime
import uuid

class User(SQLModel, table=True):
    Id: str = Field(default_factory=lambda: str(uuid.uuid4()), primary_key=True)
    Nickname: str
    CreatedAt: datetime = Field(default_factory=datetime.utcnow)
    LastActive: datetime = Field(default_factory=datetime.utcnow)

    MatchHistory: List["MatchHistory"] = Relationship(back_populates="User")


class MatchHistory(SQLModel, table=True):
    Id: str = Field(default_factory=lambda: str(uuid.uuid4()), primary_key=True)
    UserId: str = Field(foreign_key="User.Id")
    Mode: str  # 'local' or 'match'
    Result: str  # 'win', 'lose', 'draw'
    Opponent: str
    PlayedAt: datetime = Field(default_factory=datetime.utcnow)

    User: Optional[User] = Relationship(back_populates="MatchHistory")
