import random

SUITS = ["♠", "♥", "♦", "♣"]
RANKS = ["2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"]

def generate_deck():
  return [f"{rank}{suit}" for suit in SUITS for rank in RANKS]
          
def generate_hand(deck, num_cards=5):
    return random.sample(deck, num_cards)