#ifndef SUPPORT_HPP
#define SUPPORT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Support {
  public :

    Support(){
      rayon=750;
      x=250;
      y=20;
      vitesse=1;
      angle=0;
      x_laser_1=1000;
      y_laser_1=5;
      x_laser_2=0;
      y_laser_2=50;
    };

    void rotation_support();
    void move_line(int* angle, bool AFlag, bool QFlag, sf::RectangleShape* line);

  //private :
    float rayon;
    float x;
    float y;
    int vitesse;
    float angle;
    float x_laser_1;
    float y_laser_1;
    float x_laser_2;
    float y_laser_2;

};


#endif
