//
// Created by martin on 11/28/22.
//

#include "Date_type.h"

static int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31 };

static string conversion_table[] { "Error", "January", "February",
                                   "March", "April", "May",
                                   "June", "July", "August",
                                   "September", "October", "November",
                                   "December" };

void Date_type::initialize (int month, int day, int year)
{
  if (month < 1 || month > 12)
    {
      throw runtime_error("Month is invalid");
    }
  else if (day < 1 || day > days_in_month[month])
    {
      throw runtime_error("Day is invalid");
    }
  else if (year < 1583)
    {
      throw runtime_error("Year is invalid");
    }
  m_year = year;
  m_month = month;
  m_day = day;
}

int Date_type::get_month () const
{
  return m_month;
}

int Date_type::get_year () const
{
  return m_year;
}

int Date_type::get_day () const
{
  return m_day;
}

string Date_type::get_month_as_string () const
{
  return conversion_table[m_month];
}

Date_type Date_type::adjust (int days_away) const
{
  int new_day { m_day + days_away };
  int new_month { m_month };
  int new_year { m_year };
  bool finished { false };
  int days_in_this_month;
  Date_type return_date { };

  while (!finished)
    {
      days_in_this_month = days_in_month[new_month];
      if (new_month == 2)
        {
          if (((new_year % 4 == 0) && new_year % 100 != 0) || (new_year % 400 == 0))
            {
              days_in_this_month++;
            }
        }
      if (new_day <= days_in_this_month)
        {
          finished = true;
        }
      else
        {
          new_day = new_day - days_in_this_month;
          new_month = (new_month % 12) + 1;
          if (new_month == 1)
            {
              new_year++;
            }
        }
    }
  return_date.initialize(new_month, new_day, new_year);
  return return_date;
}

Relation_type Date_type::compare_to (Date_type date) const
{
  if (m_year < date.m_year)
    {
      return ::less;
    }
  else if (m_year > date.m_year)
    {
      return ::greater;
    }
  else if (m_month < date.m_month)
    {
      return ::less;
    }
  else if (m_month > date.m_month)
    {
      return ::greater;
    }
  else if (m_day < date.m_day)
    {
      return ::less;
    }
  else if (m_day > date.m_day)
    {
      return ::greater;
    }
  else
    {
      return ::equal;
    }
}
