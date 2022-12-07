//
// Created by martin on 12/5/22.
//

#pragma once

#include <bits/stdc++.h>
//#include "Item.h"
#include "Card.h"

using namespace std;

template < typename T >
struct Node;

template < typename T >
struct Node
{
    T info;
    Node *next;
};

template < typename T >
class Unsorted
{
 public:
  Unsorted () :
      m_length { 0 },
      list_data { nullptr }
  {

  }

//  virtual ~Unsorted ()
//  {
//    cout << length() << endl;
//    Node<T> *ptr;
//
//    while (list_data != nullptr)
//      {
////        cout << "deleting node" << endl;
//        ptr = list_data;
//        list_data = list_data->next;
//        delete ptr;
//      }
////    cout << "nodes deleted" << endl;
//  }

  void make_empty ()
  {
    Node<T> *ptr;

    while (list_data != nullptr)
      {
        ptr = list_data;
        list_data = list_data->next;
        delete ptr;
      }
    m_length = 0;
  }

  [[nodiscard]] static
  bool is_full ()
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

  [[nodiscard]]
  int length () const
  {
    return m_length;
  }

  T get_item (T t, bool &found)
  {
    Node<T> *location;
    location = list_data;
    bool more_to_search { location != nullptr };
    found = false;

    while (more_to_search && !found)
      {
        switch (t.compare_to(location->info))
          {
            case ::less:
            case ::greater:
              {
                location = location->next;
                more_to_search = (location != nullptr);
              }
            break;

            case ::equal:
              {
                found = true;
                t = location->info;
              }
            break;
          }
      }
    return t;
  }

  void put_item (T t)
  {
    Node<T> *location;
    location = new Node<T>;
    location->info = t;
    location->next = list_data;
    list_data = location;
    m_length++;
  }

  void delete_item (T t)
  {
    Node<T> *location { list_data };
    Node<T> *temp_location;

    if (t.compare_to(list_data->info) == ::equal) // is first node
      {
        temp_location = location;
        list_data = list_data->next;
      }
    else // find node to delete
      {
        while (t.compare_to(location->next->info) != ::equal)
          {
            location = location->next;
          }
        temp_location = location->next;
        location->next = location->next->next;
      }
    delete temp_location;
    m_length--;
  }

  void reset_list ()
  {
    current_position = nullptr;
  }

  T next_item ()
  {
    if (current_position == nullptr)
      {
        current_position = list_data;
      }
    else
      {
        current_position = current_position->next;
      }
    return current_position->info;
  }

 private:
  Node<T> *list_data;

  int m_length;

  Node<T> *current_position;
};
