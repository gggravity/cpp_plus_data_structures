#include "Sorted.h"

Sorted::Sorted ()
{
  length = 0;
  list_data = nullptr;
  current_position = nullptr;
}

Sorted::~Sorted ()
{
  Node *temp_pointer;
  while (list_data != nullptr)
    {
      temp_pointer = list_data;
      list_data = list_data->next;
      delete temp_pointer;
    }
}

bool Sorted::is_full () const
{
  Node *location;
  try
    {
      location = new Node;
      delete location;
      return false;
    }
  catch (bad_alloc &exception)
    {
      return true;
    }
}

int Sorted::get_length () const
{
  return length;
}

void Sorted::make_empty ()
{
  Node *temp_pointer;
  while (list_data != nullptr)
    {
      temp_pointer = list_data;
      list_data = list_data->next;
      delete temp_pointer;
    }
  length = 0;
}

Item Sorted::get_item (Item item, bool &found)
{
  found = false;
  Node *location = list_data;
  bool more_to_search = (location != nullptr);

  while (more_to_search && !found)
    {
      if (item > location->info)
        {
          location = location->next;
          more_to_search = (location != nullptr);
        }
      else if (item < location->info)
        {
          more_to_search = false;
        }
      else if (item == location->info)
        {
          found = true;
          item = location->info;
        }
    }
  return item;
}

void Sorted::put_item (Item item)
{
  bool more_to_search;
  Node *location = list_data;
  Node *previous_location = nullptr;
  more_to_search = (location != nullptr);

  while (more_to_search)
    {
      if (item > location->info)
        {
          previous_location = location;
          location = location->next;
          more_to_search = (location != nullptr);
        }
      else if (item < location->info)
        {
          more_to_search = false;
        }
      else if (item == location->info)
        {

        }
    }

  Node *new_node = new Node;
  new_node->info = item;

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

void Sorted::reset_list ()
{
  current_position = nullptr;
}

Item Sorted::get_next_item ()
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
