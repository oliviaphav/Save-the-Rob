#ifndef LASER_HPP
#define LASER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Laser {
  public :

    Laser(){
      angle=90;
      longueur = 750;
      largeur = 5;
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
