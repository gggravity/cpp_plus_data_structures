//
// Created by martin on 12/5/22.
//

#include "Card.h"

Card::Card () :
    rank { 1 },
    suit { club }
{

}

Card::Card (int rank, Suits suit) :
    rank(rank),
    suit(suit)
{

}

int Card::get_rank ()
{
  return rank;
}

Suits Card::get_suit ()
{
  return suit;
}

string Card::to_string () const
{
  string convert_rank[] { "Ace", "Two", "Three", "Four",
                          "Five", "Six", "Seven", "Eight",
                          "Nine", "Ten", "Jack", "Queen",
                          "King" };

  string convert_suit[] { "Clubs", "Diamonds",
                          "Hearts", "Spades" };

  return convert_rank[rank - 1] + " of " + convert_suit[suit];
}

Relation_type Card::compare_to (const Card &other) const
{
  if (suit < other.suit)
    {
      return ::less;
    }
  else if (suit > other.suit)
    {
      return ::greater;
    }
  else if (rank == other.rank)
    {
      return ::equal;
    }
  else if (rank == 1)
    {
      return ::greater;
    }
  else if (other.rank == 1)
    {
      return ::less;
    }
  else if (rank < other.rank)
    {
      return ::less;
    }
  else if (rank > other.rank)
    {
      return ::greater;
    }
  else
    {
      return ::equal;
    }
}

bool Card::operator== (const Card &rhs) const
{
  return rank == rhs.rank &&
         suit == rhs.suit;
}

bool Card::operator!= (const Card &rhs) const
{
  return !(rhs == *this);
}

bool Card::operator< (const Card &rhs) const
{
  if (rank < rhs.rank)
    {
      return true;
    }
  if (rhs.rank < rank)
    {
      return false;
    }
  return suit < rhs.suit;
}

bool Card::operator> (const Card &rhs) const
{
  return rhs < *this;
}

bool Card::operator<= (const Card &rhs) const
{
  return !(rhs < *this);
}

bool Card::operator>= (const Card &rhs) const
{
  return !(*this < rhs);
}

