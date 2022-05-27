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

  const RectangleShape* getLaser() const {return laser;};
  RectangleShape* getLaser() {return laser;};

  const float& getLongueur() const {return longueur;};
  const float& getAngle() const {return angle;};
  const bool& getEtat() const {return etat;};
  bool& getEtat() {return etat;};

  void setLongueur(float l) {longueur = l;};
  void setAngle(float a) {angle = a;};
  void setEtat(bool e) {etat = e;};

  protected :
  RectangleShape* laser;
  float longueur;
  bool etat;
  float angle;



};


#endif
