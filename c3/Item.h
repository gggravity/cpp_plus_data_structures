//
// Created by martin on 12/5/22.
//

#pragma once

#include <bits/stdc++.h>
//#include "Card.h"
//
//using namespace std;
//
//enum Relation
//{
//    less, greater, equal
//};
//
class Item
{
 public:
  Item ();

  [[nodiscard]]
  Relation compare_to (Item other) const;

  void print (ofstream &ofs) const;

  void initialize (Card card);

 private:
  Card card;
};
