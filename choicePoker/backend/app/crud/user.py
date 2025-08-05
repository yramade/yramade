from sqlalchemy.orm import Session
from app.models.user import User
from datetime import datetime
from typing import Optional

# 사용자 생성
def create_user(db: Session, name: str) -> User:
    new_user = User(name=name)
    db.add(new_user)
    db.commit()
    db.refresh(new_user)
    return new_user

# 사용자 정보 수정
def update_user_name(db: Session, user_id: int, new_name: str) -> Optional[User]:
    user = db.query(User).filter(User.id == user_id, User.deleted_at.is_(None)).first()
    if user:
        user.name = new_name
        db.commit()
        db.refresh(user)
    return user

# 사용자 soft delete (삭제 시간만 기록)
def soft_delete_user(db: Session, user_id: int) -> Optional[User]:
    user = db.query(User).filter(User.id == user_id, User.deleted_at.is_(None)).first()
    if user:
        user.deleted_at = datetime.utcnow()
        db.commit()
        db.refresh(user)
    return user

# 특정 사용자 조회
def get_user(db: Session, user_id: int) -> Optional[User]:
    return db.query(User).filter(User.id == user_id, User.deleted_at.is_(None)).first()

# 사용자 이름으로 조회
def get_user_by_name(db: Session, name: str) -> Optional[User]:
    return db.query(User).filter(User.name == name, User.deleted_at.is_(None)).first()