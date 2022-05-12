#ifndef MUR_HPP
#define MUR_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "point.hpp"


class Mur {
  public :

    Mur(const Point& c) : centre(c), rayon(740) {}
    const Point& getCentre() const  {return centre; };
    const float& getRayon() const {return rayon; };

  //private :
    float rayon;
    Point centre;

};


#endif
