#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "entite.hpp"

class Obstacle : public Entite{

  public :
    virtual void settings() const=0;


  protected :
  float x; float y;


};


#endif
