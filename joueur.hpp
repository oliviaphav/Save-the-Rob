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
  virtual ~Joueur()=default;
    virtual void settings() const=0;
    const float& getX() const  {return x; };
    const float& getY() const  {return y; };
    const float& getVitesse() const  {return vitesse; };
    const Texture* getTexture() const  {return texture; };
    const bool& getLife() const  {return life; };

    void setX(float X) {x = X;};
    void setY(float Y) {y = Y;};
    void setTexture(Texture* t) {texture = t;};
    void setVitesse(float v) {vitesse = v;};
    void setLife(bool l) {life = l;};


  protected :
    float x; float y;
    Texture *texture;
    float vitesse;
    bool life;


};


#endif
