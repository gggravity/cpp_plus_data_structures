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

  void generate ();

  void shuffle ();
};