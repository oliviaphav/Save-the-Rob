#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "laser.hpp"


void Laser::settings() const
{
  //laser->setPosition(x,y);
  laser->setFillColor(sf::Color(250, 50, 50));
  laser->setOrigin(longueur/2,0);
  laser->rotate(angle);
}

/*void Laser::settings()
{
  laser->setOrigin(longueur/2,0);
  laser->rotate(angle);
}*/
