//
// Created by martin on 12/5/22.
//

#pragma once

#include <bits/stdc++.h>

using namespace std;

enum Relation
{
    less, greater, equal
};

class Item
{
 public:
  Item ();

  explicit Item (int value);

  bool operator== (const Item &rhs) const;

  bool operator!= (const Item &rhs) const;

  bool operator< (const Item &rhs) const;

  bool operator> (const Item &rhs) const;

  bool operator<= (const Item &rhs) const;

  bool operator>= (const Item &rhs) const;

  void print (ofstream &ofs) const;

  void set_value (int number);

  friend ostream &operator<< (ostream &os, const Item &item);

 private:
  int value;
};
