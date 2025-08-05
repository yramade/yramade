import enum
from django.db import models
# from django.contrib.auth.models import User

class User(models.Model):
    id = models.AutoField(primary_key=True)
    name = models.CharField(max_length=50, unique=True)
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now_add=True)
    deleted_at = models.DateTimeField(nullable=True)

    class Meta:
        managed = True
        db_table = 'user'

class Game(models.Model):
    id = models.AutoField(primary_key=True)
    user_name = models.ForeignKey(User, models.PROTECT, db_column='name')
    player_cards = models.TextField()
    ai_cards = models.TextField()
    player_final_cards = models.TextField()
    ai_final_cards = models.TextField()
    player_hand_rank = models.CharField(max_length=50)
    ai_hand_rank = models.CharField(max_length=50)
    choice = models.CharField(max_length=10, choices=[('strong', 'Strong'), ('weak', 'Weak')])
    choice_by = models.CharField(max_length=10, choices=[('player', 'Player'), ('ai', 'Computer')])
    winner = models.CharField(max_length=10, choices=[('player', 'Player'), ('ai', 'Computer'), ('draw', 'Draw')])
    player_dice = models.IntegerField()
    ai_dice = models.IntegerField()
    created_at = models.DateTimeField(auto_now_add=True)

    class Meta:
        managed = True
        db_table  = 'game'

class Log(models.Model):
    id = models.AutoField(primary_key=True)
    game_id = models.ForeignKey(Game, models.PROTECT, db_column='id')
    event_type = models.CharField(max_length=10, choices=[
        ('deal', 'Deal'),
        ('exchange', 'Exchange'),
        ('roll', 'Roll'),
        ('choice', 'Choice'),
        ('showdown', 'Showdown')
        ])
    description = models.TextField()
    created_at = models.DateTimeField(auto_now_add=True)

    class Meta:
        managed = True
        db_table  = 'log'