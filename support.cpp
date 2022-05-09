#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "support.hpp"

void rotation_support(){

};

void Support::move_line(int* angle, bool AFlag, bool QFlag, sf::RectangleShape* line)
{
  if (AFlag)
  {
    line->rotate(*angle-1);
  }

  if (QFlag)
  {
    line->rotate(*angle+1);
  }
}
