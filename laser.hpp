#ifndef LASER_HPP
#define LASER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "arme.hpp"

class Laser : public Arme {
  public :

    Laser(){
      angle=0;
      longueur=1480;
      largeur=10;
      laser = new sf::RectangleShape;
    }

    Laser(float Angle,int Longueur, int Largueur, sf::RectangleShape *Laser){
      angle=Angle;
      longueur=Longueur;
      largeur=Largueur;
      laser = Laser;
    }
    void allumer();
    void eteindre();
    void settings() const;


  protected :
    float largeur;

};


#endif
