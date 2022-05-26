#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "entite.hpp"

using namespace sf;
using namespace std;

class Joueur : public Entite{

  public :
    /*Joueur();
    Joueur(string nom){
      this.nom = nom;
    }*/
    //virtual void deplacement() const=0;
    virtual void settings() const=0;
    const float& getX() const  {return x; };
    const float& getY() const  {return y; };
    const bool& getLife() const  {return life; };


  protected :
  float x; float y;
  //string nom;
  Texture *texture;
  float vitesse;
  bool life;


};


#endif
