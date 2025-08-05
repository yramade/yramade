from fastapi import FastAPI
from app.routers import user, game

app = FastAPI(title="초이스 포커 API")

app.include_router(user.router, prefix="/user", tags=["User"])
app.include_router(game.router, prefix="/game", tags=["Game"])
