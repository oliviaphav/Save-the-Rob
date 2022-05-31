#ifndef ARME_HPP
#define ARME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "entite.hpp"

using namespace sf;
using namespace std;

class Arme : public Entite {

  public :
    virtual void settings() const=0;

    const RectangleShape* getShape() const {return shape_arme;};
    RectangleShape* getShape() {return shape_arme;};

    const float& getLongueur() const {return longueur;};
    const float& getAngle() const {return angle;};
    const bool& getEtat() const {return etat;};
    bool& getEtat() {return etat;};

    void setLongueur(float l) {longueur = l;};
    void setAngle(float a) {angle = a;};
    void setEtat(bool e) {etat = e;};
    void setShape(RectangleShape* l) {shape_arme = l;};

  protected :
    RectangleShape* shape_arme;
    float longueur;
    bool etat;
    float angle;



};


#endif
