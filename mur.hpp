#ifndef MUR_HPP
#define MUR_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "obstacle.hpp"

#define DECALAGE 400
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT (VideoMode::getDesktopMode().height - DECALAGE)  //Hauteur de l'écran

using namespace sf;
using namespace std;

class Mur : public Obstacle {
  public :
    Mur(){
      x=0;
      y=0;
      rayon=WINDOW_HEIGHT/2;
      shape_mur = new CircleShape;
    }
    Mur(float X, float Y,CircleShape *s){
      x=X;
      y=Y;
      rayon=WINDOW_HEIGHT/2;
      shape_mur = s;
    }
    const float& getRayon() const {return rayon; };

    void settings() const;
    //void settings();

  protected :
    float rayon;
    CircleShape* shape_mur;

};


#endif
