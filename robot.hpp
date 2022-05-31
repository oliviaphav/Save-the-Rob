#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "joueur.hpp"

using namespace sf;
using namespace std;

#define DECALAGE 400
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT (VideoMode::getDesktopMode().height - DECALAGE) //Hauteur de l'écran

struct Point
{
  int x;
  int y;
};

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
    bool onSegment(Point p, Point q, Point r);
    int orientation(Point p, Point q, Point r);
    bool doIntersect(Point p1, Point q1, Point p2, Point q2);
    void collision(FloatRect* R1 , RectangleShape* R2,IntRect* rectSourceSprite);

    const Sprite* getSprite() const {return sprite;};

    void setSprite(Sprite* sp) {sprite = sp;};

  protected :
    Sprite* sprite;
};


#endif
