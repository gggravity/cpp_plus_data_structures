//
// Created by martin on 12/5/22.
//
#include "Deck.h"
#include "Card.h"

void Deck::generate ()
{
  make_empty();
  for (int suit { club } ; suit <= spade ; suit++)
    {
      Suits s = static_cast<Suits>(suit);
      for (int value { 1 } ; value <= 13 ; ++value)
        {
          put_item(Card(value, s));
//          cout << "looping" << value << " " << s << endl;
        }
    }
}

void Deck::shuffle ()
{
  srand(time(nullptr));
  Deck deck_a;
  Deck deck_b;
  Card card;
  reset_list();
  int split_size { (rand() % 8 + 1) + 22 };

  for (int i { 1 } ; i <= split_size ; ++i)
    {
      card = next_item();
      deck_a.put_item(card);
    }

  for (int i { split_size + 1 } ; i < length() ; ++i)
    {
      card = next_item();
      deck_b.put_item(card);
    }

  make_empty();

  if (split_size < (52 - split_size))
    {
      *this = merge(deck_a, deck_b);
    }
  else
    {
      *this = merge(deck_b, deck_a);
    }
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

