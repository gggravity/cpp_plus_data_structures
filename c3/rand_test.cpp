//
// Created by martin on 12/7/22.
//

#include <bits/stdc++.h>

using namespace std;

int main ()
{
  srand(time(nullptr));

  map<int, int> dist;

  for (int i { 0 } ; i < 100 ; ++i)
    {
      int split_size { (rand() % 8 + 1) + 25 };
      dist[split_size]++;
    }

  for (auto [key, value] : dist)
    {
      cout << key << " -> " << string(value, 'x') << endl;
    }
}