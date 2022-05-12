#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "support.hpp"

void Support::rotation_support(bool AFlag, bool QFlag, sf::CircleShape* shape)
{

  if (AFlag)
  {
    shape->rotate(this->direction-0.2);

  }

  if (QFlag)
  {
    shape->rotate(this->direction+0.2);
  }

};

void Support::move_laser(bool AFlag, bool QFlag, sf::RectangleShape* line, sf::RectangleShape* cube)
{
  if (AFlag)
  {
    line->rotate(this->direction-0.2);
    cube->rotate(this->direction-0.2);
  }

  if (QFlag)
  {
    line->rotate(this->direction+0.2);
    cube->rotate(this->direction+0.2);

  }
}
