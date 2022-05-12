#ifndef PORTE_LASER_HPP
#define PORTE_LASER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Porte_laser {
  public :
    Porte_laser(sf::Vector2f p, int o) : position(p), orientation(o){}

  //private :

    sf::Vector2f position;
    int orientation;

};

#endif
