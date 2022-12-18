#pragma once

#include "Sorted.hpp"
#include "Deck.h"
#include "Card.h"

class Hands
{
 public:
  Hands ();

  ~Hands ();

  explicit Hands (int players);

  void deal (int number_of_cards);

  Sorted<Card> get_hand (int which);

 private:
  int number_of_players;

  Sorted<Card> *hands;

  Deck deck;
};


