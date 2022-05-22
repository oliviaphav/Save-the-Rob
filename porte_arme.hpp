#ifndef PORTE_ARME_HPP
#define PORTE_ARME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "obstacle.hpp"
#include "arme.hpp"

class Porte_arme : public Obstacle {
  public :
    Porte_arme(){
      x=0;
      y=0;
      porte_arme = new sf::RectangleShape;
    }
    Porte_arme(float X, float Y, sf::RectangleShape* cube, Arme* a){
      x = X;
      y = Y;
      porte_arme = cube;
      arme = a;

    }
    void settings() const;
    //void settings();

  //protected:
    sf::RectangleShape* porte_arme;
    Arme* arme;

};

#endif
