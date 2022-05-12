#ifndef SUPPORT_HPP
#define SUPPORT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Support {
  public :

    Support( float x, float y){
      rayon=740;
      this->x=x;
      this->y=y;
      vitesse=1;
      angle=0;
      x_laser_1=1000;
      y_laser_1=5;
      x_laser_2=0;
      y_laser_2=5;
    };

    void rotation_support(int * angle, bool AFlag, bool QFlag, sf::CircleShape* shape);
    void move_laser(int* angle, bool AFlag, bool QFlag, sf::RectangleShape* line, sf::CircleShape* cer);
    //void move_cercle(int* angle, bool AFlag, bool QFlag,sf::CircleShape* cer );

  //private :
    float rayon;
    float x;
    float y;
    int vitesse;
    double angle;
    float x_laser_1;
    float y_laser_1;
    float x_laser_2;
    float y_laser_2;

};


#endif
