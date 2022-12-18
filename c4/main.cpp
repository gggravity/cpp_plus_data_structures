//
// Created by martin on 12/18/22.
//
#include <bits/stdc++.h>
#include "Sorted.h"
#include "Item.h"

using namespace std;

int main ()
{
  cout << "### Chapter 4 - main file ###" << endl;
  Sorted sorted;

  cout << boolalpha;
  cout << "length: " << sorted.get_length() << endl;
  cout << "is_full: " << sorted.is_full() << endl;

//  sorted.make_empty();

  Item item { 10 };
  cout << "item: " << item << endl;
  sorted.put_item(item);
  cout << "length: " << sorted.get_length() << endl;

//  auto next_item = sorted.get_next_item();
//  cout << "get_next_item: " << next_item << endl;

  bool found;
  auto new_item = sorted.get_item(item, found);
  cout << "found: " << found << endl;
  cout << "get_item: " << new_item << endl;
//
//  sorted.reset_list();

}