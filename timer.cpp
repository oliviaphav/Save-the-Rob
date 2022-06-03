#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <string>
#include <unistd.h>
#include <vector>

#include "timer.hpp"

#define DECALAGE 400
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT (VideoMode::getDesktopMode().height - DECALAGE)  //Hauteur de l'écran

void Timer::chrono(Clock* clock, Text* time, Font *font)
{

  time->setFont(*font);
  time->setCharacterSize(150);
  time->setFillColor(Color::White);
  time->setOrigin(time->getLocalBounds().width/2. , time->getLocalBounds().height/2.);

  time->setPosition(WINDOW_WIDTH/2+WINDOW_WIDTH/3,WINDOW_HEIGHT/8);

        if(secondes<=0)
        {
          minutes -=1;
          clock->restart();
        }

        Time elapsedTime = clock->getElapsedTime();
        secondes = 60 - elapsedTime.asSeconds();

  string min_str(std::to_string(minutes));
  string se_str(std::to_string(secondes));
  time->setString(min_str + " : " + se_str);
}
