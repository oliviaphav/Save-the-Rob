#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <unistd.h>
#include <vector>
#include "support.hpp"

void Support::deplacement(bool AFlag, bool QFlag)
{

  if (AFlag)
  {
    angle=vitesse;

  }

  else if (QFlag)
  {
    angle=-vitesse;
  }

  else
    angle=0;
};


void Support::settings() const
{
  shape_support->setTexture(texture);
  shape_support->setTextureRect(IntRect(300, 100, 1000, 1000));
  shape_support->setOrigin(rayon,rayon);
  shape_support->setPosition(x,y);
  shape_support->rotate(angle);

  PL1->getShape()->setFillColor(Color(250, 50, 50));
  PL1->getShape()->setOrigin(0,rayon);
  PL1->getShape()->setPosition((WINDOW_WIDTH/2),(WINDOW_HEIGHT/2));
  PL1->getShape()->rotate(angle);

  PL2->getShape()->setFillColor(Color(250, 50, 50));
  PL2->getShape()->setOrigin(rayon,0);
  PL2->getShape()->setPosition((WINDOW_WIDTH/2),(WINDOW_HEIGHT/2));
  PL2->getShape()->rotate(angle);

  PL1->getArme()->getLaser()->setOrigin(rayon,0);
  PL1->getArme()->getLaser()->setPosition(x,y);
  PL1->getArme()->getLaser()->rotate(angle);

  PL2->getArme()->getLaser()->setOrigin(rayon,0);
  PL2->getArme()->getLaser()->setPosition(x,y);
  PL2->getArme()->getLaser()->rotate(angle);

}

void Support::on_off(bool Flag1, bool Flag2)
{
  if(Flag1)
  {
    if(PL1->getArme()->getEtat()==true )
    {
      PL1->getArme()->getEtat()=false;
      cout<<"getLaser() 1 : Off"<<endl;
    }

    else
    {
      PL1->getArme()->getEtat()=true;
      cout<<"getLaser() 1 : On"<<endl;
    }

    usleep(200000);
  }

  if(Flag2)
  {
    if(PL2->getArme()->getEtat()==true)
    {
      PL2->getArme()->getEtat()=false;
      cout<<"getLaser() 2 : Off"<<endl;
    }

    else
    {
      PL2->getArme()->getEtat()=true;
      cout<<"getLaser() 2 : On"<<endl;
    }
    usleep(200000);
  }
}
