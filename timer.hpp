#ifndef TIMER_HPP
#define TIMER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace sf;
using namespace std;

class Timer {

  public :
  Timer()
  {
    minutes=2;
    secondes=0;
  };

  Timer(int min, int sec)
  {
    minutes=min;
    secondes=sec;
  };

  void decompte(Clock* clock, Text *time, Font *font);
  //Text displayClock();

  const int& getMin() const { return minutes;};
  const int& getSec() const { return secondes;};

  protected :
  int minutes;
  int secondes;
};

#endif
