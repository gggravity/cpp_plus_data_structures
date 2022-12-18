#pragma once

#include "Item.h"

struct Node;
struct Node
{
    Item info;
    Node *next;
};

class Sorted
{
 public:
  Sorted ();

  ~Sorted ();

  [[nodiscard]] bool is_full () const;

  [[nodiscard]] int get_length () const;

  void make_empty ();

  Item get_item (Item item, bool &found);

  void put_item (Item item);

  void reset_list ();

  Item get_next_item ();

 private:
  Node *list_data;

  int length;

  Node *current_position;
};


