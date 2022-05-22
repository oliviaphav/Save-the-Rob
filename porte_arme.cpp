#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "porte_arme.hpp"

/*void Porte_arme::affichage() const
{
  porte_arme->setPosition(x,y);


}*/

void Porte_arme::settings() const
{
  porte_arme->setFillColor(sf::Color(250, 50, 50));
  //porte_arme->setOrigin(740,0);
  porte_arme->setPosition(x,y);
}
