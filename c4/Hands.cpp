#include "Hands.h"
#include "Card.h"

Hands::Hands () :
    number_of_players { 0 }
{
  Sorted<Card>(); // TODO ????
}

Hands::~Hands ()
{
  delete[] hands;
}

Hands::Hands (int players) :
    number_of_players { players }
{
  hands = new Sorted<Card>[number_of_players];
  deck.generate();
}

void Hands::deal (int number_of_cards)
{
  deck.reset_list();

  for (int i { 0 } ; i < 7 ; i++) // TODO magic number
    {
      deck.shuffle();
    }

  deck.reset_list();

  for (int i { 0 } ; i < number_of_players ; ++i)
    {
      hands[i].make_empty();
    }

  for (int cards { 0 } ; cards < number_of_players ; ++cards)
    {
      for (int players { 0 } ; players < number_of_players ; players++)
        {
          auto card = deck.next_item();
          hands[players].put_item(card);
        }
    }
}

Sorted<Card> Hands::get_hand (int which)
{
  return hands[which - 1];
}
