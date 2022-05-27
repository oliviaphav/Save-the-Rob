#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "laser.hpp"


void Laser::settings() const
{
  laser->setFillColor(Color(250, 50, 50));
  laser->setOrigin(longueur/2,0);
  laser->rotate(angle);
}
