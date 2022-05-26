#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "robot.hpp"

#define SPRITE_SPEED 1
#define DECALAGE 50
#define WINDOW_WIDTH sf::VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT sf::VideoMode::getDesktopMode().height - DECALAGE //Hauteur de l'écran


void Robot::deplacement(bool upFlag, bool downFlag, bool leftFlag, bool rightFlag, sf::IntRect* rectSourceSprite)
{
  float leftside, topside, rightside, bottomside;
  leftside=x;
  topside=y;
  rightside = x + sprite->getGlobalBounds().height;
  bottomside = y + sprite->getGlobalBounds().width;
  
  // Update coordinates
  if (leftFlag)
  {
    x-=vitesse;
    if(((leftside-1440)*(leftside-1440)+ (topside-741)*(topside-741)) > (740*740) || ((leftside-1440)*(leftside-1440)+ (bottomside-741)*(bottomside-741)) > (740*740))
    //if(((leftside-1440)*(leftside-1440)+ (topside-741)*(topside-741)) > (740*740))
    {
      x+=vitesse;
    }
    rectSourceSprite->left=0;
    rectSourceSprite->top=0;

  }
  if (rightFlag)
  {
    x+=vitesse;
    if(((rightside-1440)*(rightside-1440)+ (topside-741)*(topside-741)) > (740*740) || ((rightside-1440)*(rightside-1440)+ (bottomside-741)*(bottomside-741)) > (740*740))
    //if((((leftside-1440)*(leftside-1440)+ (topside-741)*(topside-741)) > (740*740)) || (((rightside-1440)*(rightside-1440)+ (bottomside-741)*(bottomside-741)) > (740*740)))
    {
      x-=vitesse;
    }
    rectSourceSprite->left=128;
    rectSourceSprite->top=98;
  }
  if (upFlag)
  {
    y-=vitesse;
    if(((leftside-1440)*(leftside-1440)+ (topside-741)*(topside-741)) > (740*740) || ((rightside-1440)*(rightside-1440)+ (topside-741)*(topside-741)) > (740*740))
    //if((((leftside-1440)*(leftside-1440)+ (topside-741)*(topside-741)) >= (740*740)) || (((rightside-1440)*(rightside-1440)+ (bottomside-741)*(bottomside-741)) >= (740*740)))
    {
      y+=vitesse;
    }
    rectSourceSprite->left=0;
    rectSourceSprite->top=98;
  }

  if (downFlag)
  {
    y+=vitesse;
    if(((leftside-1440)*(leftside-1440)+ (bottomside-741)*(bottomside-741)) > (740*740) || ((rightside-1440)*(rightside-1440)+ (bottomside-741)*(bottomside-741)) > (740*740))
    //if((((leftside-1440)*(leftside-1440)+ (topside-741)*(topside-741)) > (740*740)) || (((rightside-1440)*(rightside-1440)+ (bottomside-741)*(bottomside-741)) > (740*740)))
    {
      y-=vitesse;
    }
    rectSourceSprite->left=0;
    rectSourceSprite->top=98;

  }

  /*if (x<0) x=0;
  if ((x + sprite->getGlobalBounds().width) > WINDOW_WIDTH) x=(WINDOW_WIDTH-sprite->getGlobalBounds().width);
  if (y<0) y=0;
  if ((y + sprite->getGlobalBounds().height) > WINDOW_HEIGHT) y=(WINDOW_HEIGHT-sprite->getGlobalBounds().height);*/

}

void Robot::settings() const
{
  sprite->setPosition(x,y);
}

void Robot::collision( sf::FloatRect* R1 , sf::RectangleShape* R2 )
    {
      float TL_x1,TL_y1,BR_x1,BR_y1;
      sf::Vector2f TL2,BR2;
      TL_x1 = R1->left;
      TL_y1 = R1->top;
      BR_x1 = R1->left + R1->height;
      BR_y1 = R1->top + R1->width;

      TL2=R2->getTransform().transformPoint(R2->getPoint(0));
      BR2=R2->getTransform().transformPoint(R2->getPoint(2));

      if ((TL_x1  >  BR2.x  )||  (BR_x1  <  TL2.x )  || ( TL_y1 > BR2.y ) || (BR_y1  < TL2.y ) )
      {
        std:: cout<<"Pas de collision"<<std::endl;
      }
      else
       {
          std::cout<<"Collision"<<std::endl;
       }
      }
