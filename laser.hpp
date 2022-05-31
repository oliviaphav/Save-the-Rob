#ifndef LASER_HPP
#define LASER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "arme.hpp"

#define DECALAGE 400
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT (VideoMode::getDesktopMode().height - DECALAGE) //Hauteur de l'écran

using namespace sf;
using namespace std;

class Laser : public Arme {
  public :

    Laser(){
      angle=0;
      longueur=WINDOW_HEIGHT/2;
      largeur=10;
      shape_arme = new RectangleShape;
      etat=false;
    }

    Laser(float Angle,int Longueur, int Largueur, RectangleShape *Laser){
      angle=Angle;
      longueur=Longueur;
      largeur=Largueur;
      shape_arme = Laser;
      etat=false;
    }

    void settings() const;
    const float& getLargeur() const {return largeur;};
    void setLargeur(float l) {largeur = l;};


  protected :
    float largeur;

};


#endif
