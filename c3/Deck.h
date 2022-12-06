//
// Created by martin on 12/5/22.
//

#pragma once

#include "Unsorted.hpp"
#include "Item.h"

struct Deck : Unsorted<Item>
{
 public:

  void generate ();

  void shuffle ();
};