#ifndef LASER_HPP
#define LASER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "arme.hpp"

using namespace sf;
using namespace std;

class Laser : public Arme {
  public :

    Laser(){
      angle=0;
      longueur=1480;
      largeur=10;
      laser = new RectangleShape;
      etat=false;
    }

    Laser(float Angle,int Longueur, int Largueur, RectangleShape *Laser){
      angle=Angle;
      longueur=Longueur;
      largeur=Largueur;
      laser = Laser;
      etat=false;
    }
    //void on_off(bool *Flag);

    void settings() const;


  protected :
    float largeur;
    //bool etat;

};


#endif
