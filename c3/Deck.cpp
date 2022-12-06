//
// Created by martin on 12/5/22.
//
#include "Deck.h"
#include "Card.h"

void Deck::generate ()
{
  make_empty();
  for (Suits suit { club } ; suit <= spade ; ++suit)
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

Deck Deck::merge (Deck shorter_deck, Deck longer_deck)
{
  Deck deck;
  Card card;
  shorter_deck.reset_list();
  longer_deck.reset_list();

  for (int counter { 1 } ; counter <= shorter_deck.length() ; ++counter)
    {
      card = shorter_deck.next_item();
      deck.put_item(card);
      card = longer_deck.next_item();
      deck.put_item(card);
    }

  auto remaining { longer_deck.length() - shorter_deck.length() };

  for (int counter { 1 } ; counter <= remaining ; ++counter)
    {
      card = longer_deck.next_item();
      deck.put_item(card);
    }
  return deck;
}

