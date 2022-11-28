#include <bits/stdc++.h>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include "Date_type.h"

using namespace std;

TEST_CASE("Valid date", "[Initialize]")
{
  Date_type date { };
  date.initialize(1, 1, 1956);

  REQUIRE(date.get_month() == 1);
  REQUIRE(date.get_day() == 1);
  REQUIRE(date.get_year() == 1956);
}

TEST_CASE("Invalid date", "[Initialize]")
{
  Date_type date { };
  CHECK_THROWS(date.initialize(0, 1, 1956));
  CHECK_THROWS(date.initialize(13, 1, 1956));
  CHECK_THROWS(date.initialize(1, 0, 1956));
  CHECK_THROWS(date.initialize(1, 32, 1956));
  CHECK_THROWS(date.initialize(1, 1, 1492));
}

TEST_CASE("less", "[compare_to]")
{
  Date_type date1 { };
  Date_type date2 { };

  date1.initialize(1, 1, 2007);
  date2.initialize(2, 1, 2007);
  REQUIRE(date1.compare_to(date2) == ::less);

  date1.initialize(1, 2, 2007);
  date2.initialize(1, 3, 2007);
  REQUIRE(date1.compare_to(date2) == ::less);

  date1.initialize(1, 1, 2006);
  date2.initialize(1, 1, 2007);
  REQUIRE(date1.compare_to(date2) == ::less);
}

TEST_CASE("greater", "[compare_to]")
{
  Date_type date1 { };
  Date_type date2 { };

  date1.initialize(2, 1, 2007);
  date2.initialize(1, 2, 2007);
  REQUIRE(date1.compare_to(date2) == ::greater);

  date1.initialize(1, 3, 2007);
  date2.initialize(1, 2, 2007);
  REQUIRE(date1.compare_to(date2) == ::greater);

  date1.initialize(1, 1, 2007);
  date2.initialize(1, 1, 2006);
  REQUIRE(date1.compare_to(date2) == ::greater);
}

TEST_CASE("equal", "[compare_to]")
{
  Date_type date1 { };
  Date_type date2 { };

  date1.initialize(1, 1, 2008);
  date2.initialize(1, 1, 2008);
  REQUIRE(date1.compare_to(date2) == ::equal);
}

TEST_CASE("adjust", "[adjust]")
{
  Date_type date { };

  date.initialize(1, 1, 2006);
  date = date.adjust(367);
  cout << date.get_day() << endl;
  cout << date.get_month() << endl;
  cout << date.get_year() << endl;
  REQUIRE(date.get_month() == 1);
  REQUIRE(date.get_day() == 3);
  REQUIRE(date.get_year() == 2007);

  date.initialize(2, 27, 2000);
  date = date.adjust(3);
  REQUIRE(date.get_month() == 3);
  REQUIRE(date.get_day() == 1);
  REQUIRE(date.get_year() == 2000);

  date.initialize(2, 27, 2100);
  date = date.adjust(3);
  REQUIRE(date.get_month() == 3);
  REQUIRE(date.get_day() == 2);
  REQUIRE(date.get_year() == 2100);

  date.initialize(2, 27, 1964);
  date = date.adjust(3);
  REQUIRE(date.get_month() == 3);
  REQUIRE(date.get_day() == 1);
  REQUIRE(date.get_year() == 1964);
}