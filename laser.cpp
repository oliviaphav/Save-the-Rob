#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "laser.hpp"


void Laser::settings() const
{
  shape_arme->setFillColor(Color(250, 50, 50));
  shape_arme->setOrigin(longueur/2,0);
  shape_arme->rotate(angle);
}
