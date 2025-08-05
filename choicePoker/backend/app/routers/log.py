from fastapi import APIRouter, Depends, HTTPException
from sqlalchemy.orm import Session
from crud import log as crud_log
from schemas import log as schema_log
from dependencies import get_db

router = APIRouter(prefix="/log", tags=["log"])

@router.post("/", response_model=schema_log.Log)  # 로그 생성
def create_log(log: schema_log.Log, db: Session = Depends(get_db)):
    return crud_log.write_log(db, log)

@router.get("/{log_id}", response_model=schema_log.Log)  # 특정 로그 조회
def get_log(log_id: int, db: Session = Depends(get_db)):
    db_log = crud_log.get_log_by_id(db, log_id)
    if not db_log:
        raise HTTPException(status_code=404, detail="로그가 존재하지 않습니다.")
    return db_log

@router.get("/game/{game_id}", response_model=list[schema_log.Log])  # 게임별 로그 조회
def get_logs_by_game(game_id: int, db: Session = Depends(get_db)):
    db_logs = crud_log.get_logs_by_game(db, game_id)
    if not db_logs:
        raise HTTPException(status_code=404, detail="해당 게임의 로그가 존재하지 않습니다.")
    return db_logs

@router.get("/game/{game_id}/latest", response_model=schema_log.Log)  # 게임별 최신 로그 조회
def get_latest_log_by_game(game_id: int, db: Session = Depends(get_db)):
    db_log = crud_log.get_latest_log_by_game(db, game_id)
    if not db_log:
        raise HTTPException(status_code=404, detail="해당 게임의 최신 로그가 존재하지 않습니다.")
    return db_log