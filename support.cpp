#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "support.hpp"

void Support::rotation_support(int * angle, bool AFlag, bool QFlag, sf::CircleShape* shape)
{

  if (AFlag)
  {
    shape->rotate(*angle-1);

  }

  if (QFlag)
  {
    shape->rotate(*angle+1);
  }

};

void Support::move_laser(int* angle, bool AFlag, bool QFlag, sf::RectangleShape* line, sf::CircleShape* cer)
{
  if (AFlag)
  {
    line->rotate(*angle-0.2);
    cer->rotate(*angle-0.2);
  }

  if (QFlag)
  {
    line->rotate(*angle+0.2);
    cer->rotate(*angle+0.2);

  }
}
