#include <bits/stdc++.h>
#include "c1/Fraction_type.h"

using namespace std;

enum test { quit, initialize, get_numerator, get_denominator, is_zero, is_not_proper };

int main ()
{
  ifstream in_file { "../c1/test.txt" };
  ofstream out_file { "../c1/results.txt" };

  int num_commands { 0 };

  Fraction_type fraction;
  for (string command ; getline(in_file, command) ; /* */)
    {
      if (command == "quit")
        {
          cout << "Testing completed." << endl;
          exit(EXIT_SUCCESS);
        }
      else if (command == "initialize")
        {
          int numerator, denominator;
          in_file >> numerator;
          in_file >> denominator;
          fraction.initialize(numerator, denominator);
          out_file << "Numerator:" << fraction.get_numerator()
                   << " Denominator: " << fraction.get_denominator() << endl;
        }
      else if (command == "get_numerator")
        {
          out_file << "Numerator: " << fraction.get_numerator() << endl;
        }
      else if (command == "get_denominator")
        {
          out_file << "Denominator: " << fraction.get_denominator() << endl;
        }
      else if (command == "is_zero")
        {
          if (fraction.is_zero())
            {
              out_file << "Fraction is zero " << endl;
            }
          else
            {
              out_file << "Fraction is not zero" << endl;
            }
        }
      else if (command == "is_not_proper")
        {
          if (fraction.is_not_proper())
            {
              out_file << "Fraction is improper " << endl;
            }
          else
            {
              out_file << "Fraction is proper " << endl;
            }
        }
      else
        {
          out_file << "Whole number is " << fraction.convert_to_proper() << endl;
          out_file << "Numerator: " << fraction.get_numerator()
                   << " Denominator: " << fraction.get_denominator() << endl;
        }
      cout << "Command number " << ++num_commands << " completed." << endl;
    }
}