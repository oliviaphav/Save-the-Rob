#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "porte_arme.hpp"


void Porte_arme::settings() const
{
  porte_arme->setFillColor(Color(250, 50, 50));
  porte_arme->setPosition((WINDOW_WIDTH/2),(WINDOW_HEIGHT/2));
}
