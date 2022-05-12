#ifndef LASER_HPP
#define LASER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Laser {
  public :

    Laser(float angle){
      this->angle=angle;
      longueur = 1480;
      largeur = 10;
      etat= true;
    }
    void allumer();
    void eteindre();


  //private :

    float angle;
    float longueur;
    float largeur;
    //Vector2f direction;
    bool etat;

};


#endif
