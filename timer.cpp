#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <string>
#include <unistd.h>
#include <vector>

#include "timer.hpp"

void Timer::decompte(Clock* clock, Text* time, Font *font)
{

  time->setFont(*font);
  time->setCharacterSize(80);
  time->setFillColor(Color::White);
  time->setOrigin(time->getLocalBounds().width/2. , time->getLocalBounds().height/2.);

        Time elapsed1 = clock->getElapsedTime();
        secondes = 60 - elapsed1.asSeconds();
        if(secondes<0)
        {
          minutes -=1;
          clock->restart();
        }

  cout<<minutes <<" min | ";
  cout <<secondes <<" sec |" <<endl;

  string min_str(std::to_string(minutes));
  string se_str(std::to_string(secondes));
  time->setString(min_str + " : " + se_str);
}

/*Text Timer::displayClock()
{

  Font font;
  font.loadFromFile("ressources/poppins.ttf");

  Text time;
  time.setFont(font);
  time.setCharacterSize(60);
  time.setFillColor(Color::White);
  time.setOrigin(time.getLocalBounds().width/2. , time.getLocalBounds().height/2.);

  string min_str(std::to_string(minutes));
  string se_str(std::to_string(secondes));
  time.setString(min_str + " : " + se_str);

  return time;
}*/
