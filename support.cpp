#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
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

/*void Support::move_arme(bool AFlag, bool QFlag, sf::RectangleShape* line, sf::RectangleShape* cube)
{
  if (AFlag)
  {
    line->rotate(this->angle-0.2);
    cube->rotate(this->angle-0.2);
  }

  if (QFlag)
  {
    line->rotate(this->angle+0.2);
    cube->rotate(this->angle+0.2);

  }
}*/

/*void Support::affichage() const
{
  shape_support->setPosition(x,y);
  shape_support->rotate(angle);
  PL1->porte_arme->setPosition(1440,743);
  PL1->porte_arme->rotate(angle);
  PL2->porte_arme->setPosition(1440,743);
  PL2->porte_arme->rotate(angle);
  PL1->arme->laser->setPosition(x,y);
  PL1->arme->laser->rotate(angle);
  PL2->arme->laser->setPosition(x,y);
  PL2->arme->laser->rotate(angle);
}*/

void Support::settings() const
{
  shape_support->setTexture(texture);
  shape_support->setTextureRect(sf::IntRect(300, 100, 1000, 1000));
  shape_support->setOrigin(rayon,rayon);
  shape_support->setPosition(x,y);
  shape_support->rotate(angle);

  PL1->porte_arme->setFillColor(sf::Color(250, 50, 50));
  PL1->porte_arme->setOrigin(0,rayon);
  PL1->porte_arme->setPosition(1440,743);
  PL1->porte_arme->rotate(angle);

  PL2->porte_arme->setFillColor(sf::Color(250, 50, 50));
  PL2->porte_arme->setOrigin(rayon,0);
  PL2->porte_arme->setPosition(1440,743);
  PL2->porte_arme->rotate(angle);

  PL1->arme->laser->setOrigin(rayon,0);
  PL1->arme->laser->setPosition(x,y);
  PL1->arme->laser->rotate(angle);

  PL2->arme->laser->setOrigin(rayon,0);
  PL2->arme->laser->setPosition(x,y);
  PL2->arme->laser->rotate(angle);

}

void Support::on_off(bool Flag1, bool Flag2)
{
  if(Flag1)
  {
    if(PL1->arme->etat==true)
    {
      PL1->arme->etat=false;
      std::cout<<"Laser 1 : Off"<<std::endl;
    }

    else
    {
      PL1->arme->etat=true;
      std::cout<<"Laser 1 : On"<<std::endl;
    }

  }

  if(Flag2)
  {
    if(PL2->arme->etat==true)
    {
      PL2->arme->etat=false;
      std::cout<<"Laser 2 : Off"<<std::endl;
    }

    else
    {
      PL2->arme->etat=true;
      std::cout<<"Laser 2 : On"<<std::endl;
    }
  }
}
