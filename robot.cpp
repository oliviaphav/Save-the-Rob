#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#define SPRITE_SPEED 1

void move(int* x, int* y, bool upFlag, bool downFlag, bool leftFlag, bool rightFlag, sf::IntRect* rectSourceSprite)
{

  // Update coordinates
  if (leftFlag)
  {
    *x-=SPRITE_SPEED;
    rectSourceSprite->left=0;
    rectSourceSprite->top=0;

  }
  if (rightFlag)
  {
    *x+=SPRITE_SPEED;
    rectSourceSprite->left=128;
    rectSourceSprite->top=98;
  }
  if (upFlag)
  {
    *y-=SPRITE_SPEED;
    rectSourceSprite->left=0;
    rectSourceSprite->top=98;
  }

  if (downFlag)
  {
    *y+=SPRITE_SPEED;
    rectSourceSprite->left=0;
    rectSourceSprite->top=98;

  }

}
