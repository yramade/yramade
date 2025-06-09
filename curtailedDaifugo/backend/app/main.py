from fastapi import FastAPI
from threading import Thread
from contextlib import asynccontextmanager

from app.models import SQLModel
from app.database import engine
from app.routers import user, game, history
from app.routers.game import cleanExpiredSessions

@asynccontextmanager
async def lifespan(app: FastAPI):
  SQLModel.metadata.create_all(engine)
  Thread(target=cleanExpiredSessions, daemon=True).start()
  yield # 종료 시점까지 대기기

app = FastAPI()

# 라우터 등록
app.include_router(user.router)
app.include_router(game.router)
app.include_router(history.router)