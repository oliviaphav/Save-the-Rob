#ifndef ENTITE_HPP
#define ENTITE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace sf;
using namespace std;

class Entite {

  public :
    virtual void settings() const=0;
    //virtual void collision(FloatRect* R1 , RectangleShape* R2) const=0;

};


#endif
