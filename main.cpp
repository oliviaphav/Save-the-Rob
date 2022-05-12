#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "robot.hpp"
#include "support.hpp"
#include "mur.hpp"
#include "laser.hpp"
#include "point.hpp"
#include "porte_laser.hpp"

#define SPRITE_SPEED 1

#define DECALAGE 50
#define WINDOW_WIDTH sf::VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT sf::VideoMode::getDesktopMode().height - DECALAGE //Hauteur de l'écran


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Save the Rob !");
    sf::Texture texture;
    if (!texture.loadFromFile("ressources/fond.jpg"))
      return -1;


    sf::Texture texture1;
    if (!texture1.loadFromFile("ressources/robot.png"))
      return -1;
    texture1.setSmooth(true);

    sf::Texture texture2;
    if (!texture2.loadFromFile("ressources/support.jpg"))
      return -1;
    texture1.setSmooth(true);

    sf::Sprite fond;
    fond.scale(3.f, 3.f);
    fond.setTexture(texture);

    sf::IntRect rectSourceSprite(0,0,54,50);

    sf::Sprite sprite(texture1,rectSourceSprite);
    sprite.setTextureRect(rectSourceSprite);
    sprite.setScale(4.f, 4.f);
    sf::Clock timer;


    Point centre(window.getSize().x/2.,window.getSize().y/2.);

    // Sprite coordinates
    int x=centre.getX();
    int y=centre.getY();

    int x_cer = centre.getX();
    int y_cer = centre.getY();


    // Flags for key pressed
    bool upFlag=false;
    bool downFlag=false;
    bool leftFlag=false;
    bool rightFlag=false;
    bool AFlag=false;
    bool QFlag=false;


    Robot* rob = new Robot();
    Support* support = new Support(centre);
    Laser* laser1 = new Laser(90);
    Laser* laser2 = new Laser(0);
    Porte_laser* pl1 = new Porte_laser(support->pos_pl1,90);
    Porte_laser* pl2 = new Porte_laser(support->pos_pl2,0);
    Mur *mur = new Mur(centre);

    sf::RectangleShape line1(sf::Vector2f(laser1->longueur, laser1->largeur));
    line1.setFillColor(sf::Color(250, 50, 50));
    line1.rotate(laser1->angle);

    sf::RectangleShape line2(sf::Vector2f(laser2->longueur, laser2->largeur));
    line2.setFillColor(sf::Color(250, 50, 50));
    line2.rotate(laser2->angle);


    sf::CircleShape shape_support(support->rayon);
    //shape.setFillColor(sf::Color::Transparent);
    shape_support.setTexture(&texture2);
    shape_support.setTextureRect(sf::IntRect(300, 100, 1000, 1000));
    shape_support.setOrigin(support->rayon,support->rayon);

    sf::RectangleShape cube1(sf::Vector2f(50, 50));
    cube1.setFillColor(sf::Color(250, 50, 50));
    cube1.setOrigin(0,support->rayon);

    sf::RectangleShape cube2(sf::Vector2f(50,50));
    cube2.setFillColor(sf::Color(250, 50, 50));
    cube2.setOrigin(support->rayon,0);

    line1.setOrigin(laser1->longueur/2,0);
    line2.setOrigin(laser2->longueur/2,0);

    sf::CircleShape shape_mur(mur->rayon);
    shape_mur.setFillColor(sf::Color::Transparent);
    shape_mur.setOrigin(mur->rayon,mur->rayon);

    shape_mur.setOutlineThickness(10);
    shape_mur.setOutlineColor(sf::Color(255, 255, 255));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        // If a key is pressed
          if (event.type == sf::Event::KeyPressed)
          {
              switch (event.key.code)
              {
              // If escape is pressed, close the application
              case  sf::Keyboard::Escape : window.close(); break;

              // Process the up, down, left and right keys
              case sf::Keyboard::Up :     upFlag=true;break;
              case sf::Keyboard::Down:    downFlag=true;break;
              case sf::Keyboard::Left:    leftFlag=true; break;
              case sf::Keyboard::Right:   rightFlag=true; break;
              case sf::Keyboard::A:       AFlag=true;break;
              case sf::Keyboard::Q:       QFlag=true; break;
              default : break;
              }
          }


        // If a key is released
            if (event.type == sf::Event::KeyReleased)
            {
                switch (event.key.code)
                {
                // Process the up, down, left and right keys
                case sf::Keyboard::Up :     upFlag=false; break;
                case sf::Keyboard::Down:    downFlag=false; break;
                case sf::Keyboard::Left:    leftFlag=false; break;
                case sf::Keyboard::Right:   rightFlag=false; break;
                case sf::Keyboard::A:       AFlag=false; break;
                case sf::Keyboard::Q:       QFlag=false; break;
                default : break;
                }
            }
      }

        rob->move(&x,&y,upFlag,downFlag,leftFlag,rightFlag,&rectSourceSprite);

        support->rotation_support(AFlag, QFlag, &shape_support);

        support->move_laser(AFlag, QFlag,&line1,&cube1);
        support->move_laser(AFlag, QFlag,&line2,&cube2);

        sf::FloatRect boundingBox = sprite.getGlobalBounds();

        sf::FloatRect otherBox = line1.getGlobalBounds();
        sf::FloatRect otherBox2 = line2.getGlobalBounds();
        if (boundingBox.intersects(otherBox))
        {
          printf("Collision line 1\n");
        }

        if (boundingBox.intersects(otherBox2))
        {
          printf("Collision line 2\n");
        }



        // Check screen boundaries
        if (x<0) x=0;
        if ((x + sprite.getGlobalBounds().width) > WINDOW_WIDTH) x=(WINDOW_WIDTH-sprite.getGlobalBounds().width);
        if (y<0) y=0;
        if ((y + sprite.getGlobalBounds().height) > WINDOW_HEIGHT) y=(WINDOW_HEIGHT-sprite.getGlobalBounds().height);

        window.clear();
        // Rotate and draw the sprite
        sprite.setTextureRect(rectSourceSprite);
        sprite.setPosition(x,y);
        shape_support.setPosition(centre.getX(),centre.getY());
        shape_mur.setPosition(centre.getX(),centre.getY());
        line1.setPosition(centre.getX(),centre.getY());
        line2.setPosition(centre.getX(),centre.getY());

        cube1.setPosition(centre.getX(),centre.getY());
        cube2.setPosition(centre.getX(),centre.getY());

        window.draw(fond);
        window.draw(shape_support);
        window.draw(shape_mur);
        window.draw(cube1);
        window.draw(cube2);
        window.draw(line1);
        window.draw(line2);
        window.draw(sprite);
        window.display();
      }

    return 0;
}
