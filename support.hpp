#ifndef SUPPORT_HPP
#define SUPPORT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "joueur.hpp"
#include "porte_arme.hpp"

using namespace sf;
using namespace std;

#define DECALAGE 400
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT (VideoMode::getDesktopMode().height - DECALAGE)  //Hauteur de l'écran


class Support : public Joueur {
  public :
  Support(){
    x=0;
    y=0;
    angle=0;
    vitesse=0;
    shape_support = new CircleShape;
    texture = new Texture;
    rayon=(WINDOW_HEIGHT/2);
    PL1 = new Porte_arme();
    PL2 = new Porte_arme();
    life=true;
  }
    Support(float X,float Y,int Angle, CircleShape *s,Texture *t,RectangleShape *cube1, RectangleShape *cube2, Arme* a1, Arme* a2)
    {
      x=X;
      y=Y;
      angle=Angle;
      shape_support=s;
      texture=t;
      rayon=(WINDOW_HEIGHT/2);
      PL1 = new Porte_arme(rayon,0,cube1, a1);
      PL2 = new Porte_arme(0,rayon,cube2, a2);
      vitesse=0.2;
      life=true;

    }

    void settings() const;

    void deplacement(bool AFlag, bool QFlag);
    void on_off(bool Flag1, bool Flag2);

    const float& getRayon() const {return rayon; };
    const float& getAngle() const {return angle; };
    const Porte_arme* getPorteArme1() const  {return PL1; };
    const Porte_arme* getPorteArme2() const  {return PL2; };
    const CircleShape* getShape() const  {return shape_support; };

    void setRayon(float r) {rayon = r; };
    void setAngle(float a) {angle = a; };
    void setPorteArme1(Porte_arme* pl) {PL1 = pl; };
    void setPorteArme2(Porte_arme* pl) {PL2 = pl; };
    void setShape(CircleShape* s) {shape_support = s; };

  protected :
    float rayon;
    Porte_arme* PL1;
    Porte_arme* PL2;
    float angle;
    CircleShape* shape_support;

};


#endif
