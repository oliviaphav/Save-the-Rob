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

  // Update coordinates
  if (leftFlag)
  {
    x-=vitesse;
    rectSourceSprite->left=0;
    rectSourceSprite->top=0;

  }
  if (rightFlag)
  {
    x+=vitesse;
    rectSourceSprite->left=128;
    rectSourceSprite->top=98;
  }
  if (upFlag)
  {
    y-=vitesse;
    rectSourceSprite->left=0;
    rectSourceSprite->top=98;
  }

  if (downFlag)
  {
    y+=vitesse;
    rectSourceSprite->left=0;
    rectSourceSprite->top=98;

  }

  if (x<0) x=0;
  if ((x + sprite->getGlobalBounds().width) > WINDOW_WIDTH) x=(WINDOW_WIDTH-sprite->getGlobalBounds().width);
  if (y<0) y=0;
  if ((y + sprite->getGlobalBounds().height) > WINDOW_HEIGHT) y=(WINDOW_HEIGHT-sprite->getGlobalBounds().height);

}

void Robot::settings() const
{
  sprite->setPosition(x,y);
}
