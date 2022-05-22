#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "entite.hpp"

class Joueur : public Entite{

  public :
    /*Joueur();
    Joueur(string nom){
      this.nom = nom;
    }*/
    //virtual void deplacement() const=0;
    virtual void settings() const=0;


  protected :
  float x; float y;
  //string nom;
  sf::Texture *texture;
  float vitesse;


};


#endif
