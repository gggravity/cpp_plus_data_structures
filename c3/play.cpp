//
// Created by martin on 12/6/22.
//

#include <bits/stdc++.h>
#include "Deck.h"

using namespace std;

void print_deck (Deck deck)
{
  if (deck.length() == 0)
    {
      cout << "Deck is empty." << endl;
    }
  else
    {
      deck.reset_list();
      Card card;
      for (int i { 1 } ; i <= deck.length() ; ++i)
        {
          card = deck.next_item();
          cout << card.to_string() << endl;
        }
    }
  cout << endl;
}

int main ()
{
  Deck deck;
  Card card;

  cout << "Deck after default constructor" << endl;
  print_deck(deck);
  deck.generate();
  cout << "Deck after generate" << endl;
  print_deck(deck);

  for (int i { 1 } ; i <= 10 ; ++i)
    {
      deck.shuffle();
    }

  cout << "Deck after ten shuffles" << endl;
  print_deck(deck);
}