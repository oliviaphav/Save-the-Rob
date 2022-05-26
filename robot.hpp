#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "joueur.hpp"

using namespace sf;
using namespace std;

class Robot : public Joueur {

public :
    Robot(){
      x=0;
      y=0;
      vitesse=1;
      sprite = new Sprite;
      texture = new Texture;
      life=true;
    }

    Robot(float X, float Y, float Vitesse,Sprite *s , Texture *t){
      x=X;
      y=Y;
      sprite = s;
      texture = t;
      vitesse=Vitesse;
      life=true;
    }
    void deplacement(bool upFlag, bool downFlag, bool leftFlag, bool rightFlag, IntRect* rectSourceSprite);
    void settings() const;
    void collision(FloatRect* R1 , RectangleShape* R2);


  protected :
    Sprite* sprite;
};


#endif
