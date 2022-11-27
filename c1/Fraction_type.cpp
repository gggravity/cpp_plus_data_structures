#include "Fraction_type.h"

Fraction_type::Fraction_type ()
{

}

void Fraction_type::initialize (int numerator, int denominator)
{
  this->numerator = numerator;
  this->denominator = denominator;
}

int Fraction_type::get_numerator () const
{
  return numerator;
}

int Fraction_type::get_denominator () const
{
  return denominator;
}

bool Fraction_type::is_zero () const
{
  return numerator == 0;
}

bool Fraction_type::is_not_proper () const
{
  return numerator >= denominator;
}

bool Fraction_type::convert_to_proper ()
{
  int result;
  result = numerator / denominator;
  numerator = numerator % denominator;
  if (numerator == 0)
    {
      denominator = 1;
    }
  return result;
}
