#pragma once

class Fraction_type
{
 public:
  Fraction_type ();

  void initialize (int numerator, int denominator);

  [[nodiscard]] int get_numerator () const;

  [[nodiscard]] int get_denominator () const;

  [[nodiscard]] bool is_zero () const;

  [[nodiscard]] bool is_not_proper () const;

  bool convert_to_proper ();

 private:
  int numerator;

  int denominator;
};

