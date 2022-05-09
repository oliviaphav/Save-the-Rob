#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Robot {
  public :

    Robot(){
      x=0;
      y=0;
      vitesse=1;
      vie=true;
    };
    void move(int* x, int* y, bool upFlag, bool downFlag, bool leftFlag, bool rightFlag, sf::IntRect* rectSourceSprite);

  private :
    float vitesse;
    bool vie;
    float x;
    float y;

};


#endif
