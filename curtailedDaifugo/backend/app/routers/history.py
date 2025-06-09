from fastapi import APIRouter, Depends, HTTPException
from pydantic import BaseModel
from sqlmodel import Session, select
from datetime import datetime
from typing import List

from app.database import getSesstion
from app.models import MatchHistory

router = APIRouter()

class MatchRecordCreate(BaseModel):
  userId: str
  mode: str
  result: str
  opponent: str


@router.post("/history")
def createHistory(payload: MatchRecordCreate, session: Session = Depends(getSesstion)):
  record = MatchHistory.model_construct(
    userId = payload.userId,
    mode = payload.mode,
    result = payload.result,
    opponent = payload.opponent,
    playedAt = datetime.now()
  )
  record.model_dump(by_alias=True)
  session.add(record)
  session.commit()
  session.refresh(record)
  return record


@router.get("/history/{userId}")
def get_user_history(userId: str, session: Session = Depends(getSesstion)):
  statement = select(MatchHistory).where(MatchHistory.userId == userId)
  results = session.exec(statement).all()
  if not results:
    raise HTTPException(status_code=404, detail="해당 유저의 전적이 없습니다.")
  return results