#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "robot.hpp"
#include "entite.hpp"
#include "joueur.hpp"
#include "support.hpp"
#include "obstacle.hpp"
#include "mur.hpp"
#include "jeu.hpp"
#include "porte_arme.hpp"
#include "arme.hpp"
#include "laser.hpp"

#define SPRITE_SPEED 1

#define DECALAGE 50
#define WINDOW_WIDTH sf::VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT sf::VideoMode::getDesktopMode().height - DECALAGE //Hauteur de l'écran


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Save the Rob !");
    Jeu* jeu = new Jeu();
    // Centre coordinates
    const int x=window.getSize().x/2.;
    const int y=window.getSize().y/2.;
    std::cout<<window.getSize().x/2.<<std::endl; //1440
    std::cout<<window.getSize().y/2.<<std::endl; //741

    sf::Texture texture;
    if (!texture.loadFromFile("ressources/fond.jpg"))
      return -1;
    sf::Sprite fond;
    fond.scale(3.f, 3.f);
    fond.setTexture(texture);


    sf::Texture texture1;
    if (!texture1.loadFromFile("ressources/robot.png"))
      return -1;
    texture1.setSmooth(true);
    sf::IntRect rectSourceSprite(0,0,54,50);
    sf::Sprite sprite(texture1,rectSourceSprite);
    sprite.setTextureRect(rectSourceSprite);
    sprite.setScale(3.f, 3.f);
    Robot* rob = new Robot(x,y,1, &sprite , &texture1);


    sf::Texture texture2;
    if (!texture2.loadFromFile("ressources/support.jpg"))
      return -1;
    texture1.setSmooth(true);
    sf::CircleShape shape_support(740);
    sf::RectangleShape cube1(sf::Vector2f(50, 50));
    sf::RectangleShape cube2(sf::Vector2f(50, 50));

    sf::RectangleShape line1(sf::Vector2f(1480, 10));
    line1.setFillColor(sf::Color(250, 50, 50));
    line1.rotate(90);
    Laser* laser1=new Laser(0,1480,10,&line1);
    //laser1->settings();

    sf::RectangleShape line2(sf::Vector2f(1480, 10));
    line2.setFillColor(sf::Color(250, 50, 50));
    Laser* laser2=new Laser(90,1480,10,&line2);
    //laser2->settings();

    Support* support = new Support(x,y,0,&shape_support,&texture2,&cube1,&cube2,laser1,laser2);

    //support->settings();

    sf::CircleShape shape_mur(740);
    Mur* mur = new Mur(x,y,&shape_mur);

    //mur->settings();

    // Flags for key pressed
    bool upFlag=false;
    bool downFlag=false;
    bool leftFlag=false;
    bool rightFlag=false;
    bool AFlag=false;
    bool QFlag=false;
    bool Flag1=false;
    bool Flag2=false;

    while (window.isOpen())
    {

      jeu->clavier(&upFlag,&downFlag,&leftFlag,&rightFlag,&AFlag, &QFlag, &Flag1,&Flag2, window);

      sf::FloatRect boundingBox = sprite.getGlobalBounds();

      support->on_off(Flag1,Flag2);

       rob->deplacement(upFlag,downFlag,leftFlag,rightFlag,&rectSourceSprite);
       rob->collision(&boundingBox,&line1);
       rob->collision(&boundingBox,&line2);


      support->deplacement(AFlag, QFlag);


      window.clear();

      rob->settings();
      support->settings();
      mur->settings();


      window.draw(fond);
      window.draw(shape_support);
      window.draw(shape_mur);
      window.draw(sprite);
      window.draw(cube1);
      window.draw(cube2);
      if(support->PL1->arme->etat==true)
        window.draw(line1);
      if(support->PL2->arme->etat==true)
        window.draw(line2);
      //window.draw(box);
      //window.draw(box1);
      window.display();

    }

    return 0;
}
