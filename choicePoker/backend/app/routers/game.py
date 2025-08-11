from fastapi import APIRouter, Depends, HTTPException
from schemas.game import Game, GameResponse
from sqlalchemy.orm import Session
from crud import game as crud_game
from dependencies import get_db

router = APIRouter(prefix="/game", tags=["game"])

@router.post("/", response_model=GameResponse)  # 게임 생성
def start_game(game: Game, db: Session = Depends(get_db)):
    return crud_game.start_game(db, game)

@router.get("/{game_id}", response_model=GameResponse)  # 특정 게임 조회  
def get_game(game_id: int, db: Session = Depends(get_db)):
    db_game = crud_game.get_game_by_id(db, game_id)
    if not db_game:
        raise HTTPException(status_code=404, detail="해당 게임을 찾을 수 없습니다.")
    return db_game

@router.get("/user/{user_name}", response_model=GameResponse)  # 사용자 이름으로 게임 조회
def get_game_by_user(user_name: str, db: Session = Depends(get_db)):
    db_game = crud_game.get_game_by_user(db, user_name)
    if not db_game:
        raise HTTPException(status_code=404, detail="해당 게임을 찾을 수 없습니다.")
    return db_game

@router.put("/{game_id}", response_model=GameResponse)  # 게임 정보 수정
def update_game(game_id: int, game: Game, db: Session = Depends(get_db)):
    db_game = crud_game.get_game_by_id(db, game_id)
    if not db_game:
        raise HTTPException(status_code=404, detail="해당 게임을 찾을 수 없습니다.")
    return crud_game.update_game(db, game_id, game)

@router.delete("/{game_id}", response_model=GameResponse)  # 게임 삭제  
def delete_game(game_id: int, db: Session = Depends(get_db)):
    db_game = crud_game.get_game_by_id(db, game_id)
    if not db_game:
        raise HTTPException(status_code=404, detail="해당 게임을 찾을 수 없습니다.")
    return crud_game.delete_game(db, game_id)

