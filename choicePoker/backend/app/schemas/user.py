from sqlalchemy import Column, Integer, String, DateTime, func
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()

class TimestampMixin:
    created_at = Column(DateTime, server_default=func.now(), nullable=False)
    updated_at = Column(DateTime, server_default=func.now(), onupdate=func.now(), nullable=False)
    deleted_at = Column(DateTime, nullable=True)

class User(Base, TimestampMixin):
    __tablename__ = "user"

    id = Column(Integer, primary_key=True, index=True)
    name = Column(String(50), unique=True, nullable=False)
    created_at = TimestampMixin.created_at
    updated_at = TimestampMixin.updated_at
    deleted_at = TimestampMixin.deleted_at


# from sqlalchemy import Column, Integer, String, DateTime, func
# from sqlalchemy.ext.declarative import declarative_base
# from sqlalchemy.orm import declared_attr

# Base = declarative_base()



# class User(Base, TimestampMixin):
#     __tablename__ = "User"

#     id = Column(Integer, primary_key=True, index=True)
#     name = Column(String(50), unique=True, nullable=False)

# def soft_delete_user(db_session, user_id: int):
#     user = db_session.query(User).filter(User.id == user_id).first()
#     if user:
#         user.deleted_at = datetime.utcnow()
#         db_session.commit()


# from pydantic import BaseModel
# from datetime import datetime
# 
# class UserModel(BaseModel):
#     id: AutoField(REQUIRED, primary_key=True)
#     name: StringField(max_length=50) # , unique=True
#     created_at: DateTimeField(REQUIRED, format="%Y%m%d%H%M%S", auto_now_add=True)
# 
#     def createUser(self, name: str):
#         self.name = name
#         self.created_at = datetime.now()
#         return self
# 
#     def getUser(self, name: str):
#         return self