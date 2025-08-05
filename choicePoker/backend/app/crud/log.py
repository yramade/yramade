from sqlalchemy.orm import Session
from app.models.log import Log
from datetime import datetime
from typing import Optional

# 로그 생성
def writelog(db: Session, game_id: int, event_type: str, description: Optional[str] = None) -> Log:
    new_log = Log(
        game_id=game_id,
        event_type=event_type,
        description=description
    )
    db.add(new_log)
    db.commit()
    db.refresh(new_log)
    return new_log

# 특정 로그 조회
def get_log(db: Session, log_id: int) -> Optional[Log]:
    return db.query(Log).filter(Log.id == log_id).first()

# 특정 게임의 로그 조회
def get_logs_by_game(db: Session, game_id: int) -> list[Log]:
    return db.query(Log).filter(Log.game_id == game_id).all()