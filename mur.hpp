#ifndef MUR_HPP
#define MUR_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "obstacle.hpp"


class Mur : public Obstacle {
  public :
    Mur(){
      x=0;
      y=0;
      rayon=740;
      shape_mur = new sf::CircleShape;
    }
    Mur(float X, float Y,sf::CircleShape *s){
      x=X;
      y=Y;
      rayon=740;
      shape_mur = s;
    }
    const float& getRayon() const {return rayon; };

    void settings() const;
    //void settings();

  protected :
    float rayon;
    sf::CircleShape* shape_mur;

};


#endif
