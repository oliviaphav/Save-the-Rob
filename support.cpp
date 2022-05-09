#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "support.hpp"

void Support::rotation_support(float *x, float *y,int* angle, bool AFlag, bool QFlag, sf::RectangleShape* line)
{
  //std::vector<int> matrice{ cos(*angle),sin(*angle),sin(*angle),-cos(*angle)};
  if (AFlag)
  {
    *x= 200*cos(*angle-1);
    *y= 200*sin(*angle-1);
    line->rotate(*angle-1);
  }

  if (QFlag)
  {
    *x= 200*cos(*angle+1);
    *y= 200*sin(*angle+1);
    line->rotate(*angle+1);
  }


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
