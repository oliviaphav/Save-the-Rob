#ifndef SUPPORT_HPP
#define SUPPORT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "point.hpp"


class Support {
  public :

    Support(const Point& c) : centre(c), rayon(740), direction(0), pos_pl1(740,0),pos_pl2(0,740){}
    const Point& getCentre() const  {return centre; };
    const float& getRayon() const {return rayon; };

    void rotation_support(bool AFlag, bool QFlag, sf::CircleShape* shape);
    void move_laser(bool AFlag, bool QFlag, sf::RectangleShape* line, sf::RectangleShape* cube);

  //private :
    float rayon;
    Point centre;
    int direction;
    sf::Vector2f pos_pl1;
    sf::Vector2f pos_pl2;

};


#endif
