//
// Created by martin on 12/5/22.
//

#include "Item.h"

Item::Item () :
    value { 0 }
{

}

Item::Item (int value) :
    value(value)
{

}

//Relation Item::compare_to (Item other) const
//{
//  if (value < other.value)
//    {
//      return ::less;
//    }
//  else if (value > other.value)
//    {
//      return ::greater;
//    }
//  else
//    {
//      return ::equal;
//    }
//}

void Item::print (ofstream &ofs) const
{
  ofs << value << " ";
}

void Item::set_value (int number)
{
  value = number;
}

ostream &operator<< (ostream &os, const Item &item)
{
  os << item.value;
  return os;
}

bool Item::operator< (const Item &rhs) const
{
  return value < rhs.value;
}

bool Item::operator> (const Item &rhs) const
{
  return rhs < *this;
}

bool Item::operator<= (const Item &rhs) const
{
  return !(rhs < *this);
}

bool Item::operator>= (const Item &rhs) const
{
  return !(*this < rhs);
}

bool Item::operator== (const Item &rhs) const
{
  return value == rhs.value;
}

bool Item::operator!= (const Item &rhs) const
{
  return !(rhs == *this);
}
