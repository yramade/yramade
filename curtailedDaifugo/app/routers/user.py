from fastapi import APIRouter, Depends, HTTPException
from pydantic import BaseModel
from sqlmodel import Session
from datetime import datetime

from app.database import getSesstion
from app.models import User

router = APIRouter()

class UserCreate(BaseModel):
  nickname: str

# 유저 생성
@router.post("/user")
def createUser(payload: UserCreate, session: Session = Depends(getSesstion)):
  user = User.model_construct(
    nickname=payload.nickname,
    createdAt=datetime.now(),
    lastActive=datetime.now()
  )
  user.model_dump(by_alias=True)
  session.add(user)
  session.commit()
  session.refresh(user)
  return user

# 유저 조회
@router.get("/user/{userId}")
def getUser(userId: str, session: Session = Depends(getSesstion)):
  user = session.get(User, userId)
  if not user:
    raise HTTPException(status_code=404, detail="사용자를 찾을 수 없습니다.")
  return user