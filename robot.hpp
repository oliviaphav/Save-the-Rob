#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "joueur.hpp"

class Robot : public Joueur {

public :
    Robot(){
      x=0;
      y=0;
      vitesse=1;
      sprite = new sf::Sprite;
      texture = new sf::Texture;
    }

    Robot(float X, float Y, float Vitesse,sf::Sprite *s , sf::Texture *t){
      x=X;
      y=Y;
      sprite = s;
      texture = t;
      vitesse=Vitesse;
    }
    void deplacement(bool upFlag, bool downFlag, bool leftFlag, bool rightFlag, sf::IntRect* rectSourceSprite);
    void settings() const;

  protected :
    sf::Sprite* sprite;
};


#endif
