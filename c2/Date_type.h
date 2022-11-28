#include <bits/stdc++.h>

using namespace std;

enum Relation_type { less, equal, greater };

class Date_type
{
 public:
  void initialize (int month, int day, int year);

  [[nodiscard]] int get_month () const;

  [[nodiscard]] int get_year () const;

  [[nodiscard]] int get_day () const;

  [[nodiscard]] string get_month_as_string () const;

  Date_type adjust (int days_away) const;

  [[nodiscard]] Relation_type compare_to (Date_type date) const;

 private:
  int m_year;

  int m_month;

  int m_day;
};
