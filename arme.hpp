#ifndef ARME_HPP
#define ARME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "entite.hpp"

class Arme : public Entite {

  public :
  virtual void settings() const=0;

  sf::RectangleShape* laser;
  float longueur;
  bool etat;

  protected :

  float angle;



};


#endif
