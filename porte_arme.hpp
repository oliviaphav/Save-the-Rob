#ifndef PORTE_ARME_HPP
#define PORTE_ARME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "obstacle.hpp"
#include "arme.hpp"

using namespace sf;
using namespace std;

class Porte_arme : public Obstacle {
  public :
    Porte_arme(){
      x=0;
      y=0;
      porte_arme = new RectangleShape;
    }
    Porte_arme(float X, float Y, RectangleShape* cube, Arme* a){
      x = X;
      y = Y;
      porte_arme = cube;
      arme = a;

    }
    void settings() const;
    const RectangleShape* getShape() const  {return porte_arme; };
    const Arme* getArme() const  {return arme; };
    RectangleShape* getShape() {return porte_arme; };
    Arme* getArme() {return arme; };

    void setShape(RectangleShape* s) {porte_arme = s; };
    void setArme(Arme* a) {arme = a; };

  protected:
    RectangleShape* porte_arme;
    Arme* arme;

};

#endif
