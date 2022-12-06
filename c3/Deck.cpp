//
// Created by martin on 12/5/22.
//
#include "Deck.h"
#include "Card.h"

void Deck::generate ()
{
  make_empty();
  for (Suits suit { club } ; suit <= spade ; Suits(suit + 1))
    {
      for (int value { 1 } ; value <= 13 ; ++value)
        {
          put_item(Card(value, suit));
        }
    }
}

void Deck::shuffle ()
{

}

