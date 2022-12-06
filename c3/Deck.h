//
// Created by martin on 12/5/22.
//

#pragma once

#include "Unsorted.hpp"
//#include "Item.h"
#include "Card.h"

struct Deck : Unsorted<Card>
{
 public:

  [[noreturn]] void generate ();

  void shuffle ();

 private:
  Deck merge (Deck shorter_deck, Deck longer_deck);
};