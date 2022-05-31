#include "catch.hpp"
#include "timer.hpp"


TEST_CASE( "Tests classe Timer", "[timer]" ) {
  Timer t1;
  Timer t2(2,30);

  SECTION("Tests contructeurs")
  {
    REQUIRE(t1.getMin() == 1);
    REQUIRE(t1.getSec() == 0);

    REQUIRE(t2.getMin() == 2);
    REQUIRE(t2.getSec() == 30);

  }

  SECTION(" Chrono")
  {
    Clock clock; Text time; Font font;

    t1.chrono(&clock, &time, &font);
    t1.chrono(&clock, &time, &font);
    REQUIRE(t1.getMin() == 0);
    REQUIRE(t1.getSec() == 59);

  }
}
