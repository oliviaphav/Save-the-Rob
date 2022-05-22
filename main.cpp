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
    std::cout<<window.getSize().x/2.<<std::endl;
    std::cout<<window.getSize().y/2.<<std::endl;

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
    sprite.setScale(4.f, 4.f);
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

    while (window.isOpen())
    {

      jeu->clavier(&upFlag,&downFlag,&leftFlag,&rightFlag,&AFlag, &QFlag,window);

      sf::FloatRect nextPos;

      sf::FloatRect boundingBox = sprite.getGlobalBounds();

      nextPos.left=boundingBox.left+1;
      nextPos.top=boundingBox.top+1;

      /*sf::FloatRect otherBox = line1.getGlobalBounds();
      sf::FloatRect otherBox2 = line2.getGlobalBounds();

      sf::RectangleShape box(sf::Vector2f(boundingBox.height,boundingBox.width));
      box.setFillColor(sf::Color::Transparent);
      box.setOutlineThickness(10);
      box.setOutlineColor(sf::Color(255, 255, 255));

      sf::RectangleShape box1(sf::Vector2f(otherBox.height,otherBox.width));
      box1.setFillColor(sf::Color::Transparent);
      box1.setOutlineThickness(10);
      box1.setOutlineColor(sf::Color(255, 255, 255));

      if (otherBox.intersects(boundingBox))
      {
        std::cout << "Collision line 1" << "\n";
      }

      else if (otherBox2.intersects(boundingBox))
      {
        std::cout << "Collision line 2" << "\n";
      }

      else {

        std::cout << "Pas de collision" << "\n";

      }*/

      if(((nextPos.left-window.getSize().x/2.)*(nextPos.left-window.getSize().x/2.)+
         (nextPos.top-window.getSize().y/2.)*(nextPos.top-window.getSize().y/2.) >
       740*740) && (nextPos.left-window.getSize().x/2.)*(nextPos.left-window.getSize().x/2.)+
          (nextPos.top-window.getSize().y/2.)*(nextPos.top-window.getSize().y/2.) <
        750*750)
       {
         
         std::cout << "Collision Mur" << "\n";
       }

       else
       {
         std::cout << "Pas de collision" << "\n";
       }

      rob->deplacement(upFlag,downFlag,leftFlag,rightFlag,&rectSourceSprite);
      support->deplacement(AFlag, QFlag);

      window.clear();

      rob->settings();
      support->settings();
      mur->settings();

    //  box.setPosition(sprite.getPosition().x,sprite.getPosition().y);
    //  box1.setPosition(window.getSize().x/2.,window.getSize().y/2.);


      window.draw(fond);
      window.draw(shape_support);
      window.draw(shape_mur);
      window.draw(sprite);
      window.draw(cube1);
      window.draw(cube2);
      window.draw(line1);
      window.draw(line2);
      //window.draw(box);
      //window.draw(box1);
      window.display();

    }

    return 0;
}
