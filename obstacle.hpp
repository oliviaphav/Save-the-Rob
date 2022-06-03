#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "entite.hpp"

class Obstacle : public Entite{

  public :
    virtual ~Obstacle()=default;
    virtual void settings() const=0;
    const float& getX() const  {return x; };
    const float& getY() const  {return y; };
    void setX(float X){x = X; };
    void setY(float Y){y = Y; };

  protected :
    float x;
    float y;


};


#endif
