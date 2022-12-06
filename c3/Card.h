//
// Created by martin on 12/5/22.
//

#pragma once

#include <bits/stdc++.h>

using namespace std;

enum Suits { club, diamond, heart, spade };
enum Relation_type { less, equal, greater };

class Card
{
 public:
  Card ();

  Card (int rank, Suits suit);

  int get_rank ();

  Suits get_suit ();

  [[nodiscard]]
  string to_string () const;

  [[nodiscard]]
  Relation_type compare_to (const Card &other) const;

 private:
  int rank;

  Suits suit;
};
