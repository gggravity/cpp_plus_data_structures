#include <bits/stdc++.h>

using namespace std;

void increment (int &next_number)
{
  next_number++;
}

int main ()
{
  int count { 1 };

  while (count < 10)
    {
      cout << " The number after " << count;
      increment(count);
      cout << " is " << count << endl;
    }
}