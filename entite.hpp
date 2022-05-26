#ifndef ENTITE_HPP
#define ENTITE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Entite {

  public :
    virtual void settings() const=0;
    //virtual void collision(sf::FloatRect* R1 , sf::RectangleShape* R2) const=0;

};


#endif
