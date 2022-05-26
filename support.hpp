#ifndef SUPPORT_HPP
#define SUPPORT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "joueur.hpp"
#include "porte_arme.hpp"


class Support : public Joueur {
  public :
  Support(){
    x=0;
    y=0;
    angle=0;
    vitesse=0;
    shape_support = new sf::CircleShape;
    texture = new sf::Texture;
    rayon=740;
    PL1 = new Porte_arme();
    PL2 = new Porte_arme();
  }
    Support(float X,float Y,int Angle, sf::CircleShape *s,sf::Texture *t,sf::RectangleShape *cube1, sf::RectangleShape *cube2, Arme* a1, Arme* a2) {
      x=X;
      y=Y;
      angle=Angle;
      shape_support=s;
      texture=t;
      rayon=740;
      PL1 = new Porte_arme(rayon,0,cube1, a1);
      PL2 = new Porte_arme(0,rayon,cube2, a2);
      vitesse=0.2;

    }
    const float& getRayon() const {return rayon; };
    //void affichage() const;
    void settings() const;

    void deplacement(bool AFlag, bool QFlag);
    void on_off(bool Flag1, bool Flag2);
    Porte_arme* PL1;
    Porte_arme* PL2;

  protected :
    float rayon;
    //Porte_arme* PL1;
    //Porte_arme* PL2;
    float angle;
    sf::CircleShape* shape_support;

};


#endif
