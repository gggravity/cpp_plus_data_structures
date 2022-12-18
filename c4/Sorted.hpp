#pragma once

#include "Item.h"
#include "Node.hpp"

template < typename T >
class Sorted
{
 public:
  Sorted ()
  {
    length = 0;
    list_data = nullptr;
    current_position = nullptr;
  }

  ~Sorted ()
  {
    Node<T> *temp_pointer;
    while (list_data != nullptr)
      {
        temp_pointer = list_data;
        list_data = list_data->next;
        delete temp_pointer;
      }
  }

  [[nodiscard]] bool is_full () const
  {
    Node<T> *location;
    try
      {
        location = new Node<T>;
        delete location;
        return false;
      }
    catch (bad_alloc &exception)
      {
        return true;
      }
  }

  [[nodiscard]] int get_length () const
  {
    return length;
  }

  void make_empty ()
  {
    Node<T> *temp_pointer;
    while (list_data != nullptr)
      {
        temp_pointer = list_data;
        list_data = list_data->next;
        delete temp_pointer;
      }
    length = 0;
  }

  Item get_item (T t, bool &found)
  {
    found = false;
    Node<T> *location = list_data;
    bool more_to_search = (location != nullptr);

    while (more_to_search && !found)
      {
        if (t > location->info)
          {
            location = location->next;
            more_to_search = (location != nullptr);
          }
        else if (t < location->info)
          {
            more_to_search = false;
          }
        else if (t == location->info)
          {
            found = true;
            t = location->info;
          }
      }
    return t;
  }

  void put_item (T t)
  {
    bool more_to_search;
    Node<T> *location = list_data;
    Node<T> *previous_location = nullptr;
    more_to_search = (location != nullptr);

    while (more_to_search)
      {
        if (t > location->info)
          {
            previous_location = location;
            location = location->next;
            more_to_search = (location != nullptr);
          }
        else if (t < location->info)
          {
            more_to_search = false;
          }
        else if (t == location->info)
          {

          }
      }

    auto *new_node = new Node<T>;
    new_node->info = t;

    if (previous_location == nullptr)
      {
        new_node->next = list_data;
        list_data = new_node;
      }
    else
      {
        new_node->next = location;
        previous_location->next = new_node;
      }
    length++;
  }

  void reset_list ()
  {
    current_position = nullptr;
  }

  Item get_next_item ()
  {
    Item item;
    if (current_position == nullptr)
      {
        current_position = list_data;
      }
    item = current_position->info;
    current_position = current_position->next;
    return item;
  }

 private:
  Node<T> *list_data;

  int length;

  Node<T> *current_position;
};


