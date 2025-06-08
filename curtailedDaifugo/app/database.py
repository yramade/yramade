from sqlmodel import create_engine, Session

DATABASE_URL = "sqlite:///./db.splite3"
engine = create_engine(DATABASE_URL, echo = True)

def getSesstion():
  return Session(engine)