#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "mur.hpp"

void Mur::settings() const
{
  shape_mur->setFillColor(Color::Transparent);
  shape_mur->setOrigin(rayon,rayon);

  shape_mur->setOutlineThickness(10);
  shape_mur->setOutlineColor(Color(255, 255, 255));

  shape_mur->setPosition(x,y);
}
