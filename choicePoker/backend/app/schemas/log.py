from sqlalchemy import Column, Integer, String, DateTime, func
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()

class Log(Base):
    __tablename__ = "log"

    id = Column(Integer, primary_key=True, index=True)
    game_id = Column(Integer, nullable=False)
    event_type = Column(String(10), nullable=False, choices=[
        ('deal', 'Deal'),
        ('exchange', 'Exchange'),
        ('roll', 'Roll'),
        ('choice', 'Choice'),
        ('showdown', 'Showdown')
    ])
    description = Column(String, nullable=True)
    created_at = Column(DateTime, server_default=func.now(), nullable=True)