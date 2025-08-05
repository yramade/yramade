from fastapi import APIRouter, Depends, HTTPException
from sqlalchemy.orm import Session
from crud import user as crud_user
from schemas import user as schema_user
from dependencies import get_db

router = APIRouter(prefix="/user", tags=["user"])

@router.post("/", response_model=schema_user.User) # 사용자 생성
def create_user(user: schema_user.UserCreate, db: Session = Depends(get_db)):
    return crud_user.create_user(db, user)

@router.get("/{user_id}", response_model=schema_user.User) # 특정 사용자 조회
def get_user(user_id: int, db: Session = Depends(get_db)):
    db_user = crud_user.get_user_by_id(db, user_id)
    if not db_user:
        raise HTTPException(status_code=404, detail="사용자가 존재하지 않습니다.")
    return db_user

@router.get("/name/{name}", response_model=schema_user.User) # 사용자 이름으로 조회
def get_user_by_name(name: str, db: Session = Depends(get_db)):
    db_user = crud_user.get_user_by_name(db, name)
    if not db_user:
        raise HTTPException(status_code=404, detail="사용자가 존재하지 않습니다.")
    return db_user

@router.put("/{user_id}", response_model=schema_user.User) # 사용자 정보 수정
def update_user(user_id: int, user: schema_user.UserUpdate, db: Session = Depends(get_db)):
    db_user = crud_user.get_user_by_id(db, user_id)
    if not db_user:
        raise HTTPException(status_code=404, detail="사용자가 존재하지 않습니다.")
    return crud_user.update_user(db, user_id, user)

@router.delete("/{user_id}", response_model=schema_user.User)  # 사용자 삭제
def delete_user(user_id: int, db: Session = Depends(get_db)):
    db_user = crud_user.get_user_by_id(db, user_id)
    if not db_user:
        raise HTTPException(status_code=404, detail="사용자가 존재하지 않습니다.")
    return crud_user.delete_user(db, user_id) 