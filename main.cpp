#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "robot.hpp"
#include "support.hpp"
#include "laser.hpp"
#include "point.hpp"
#include <SFML/Window/Keyboard.hpp>
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

    int x_cer = window.getSize().x/2.;
    int y_cer = window.getSize().y/2.;


    // Flags for key pressed
    bool upFlag=false;
    bool downFlag=false;
    bool leftFlag=false;
    bool rightFlag=false;
    bool AFlag=false;
    bool QFlag=false;

    int angle=0;
    Robot* rob = new Robot();
    Support* support = new Support(centre.getX(),centre.getY());
    Laser* laser1 = new Laser(90);
    Laser* laser2 = new Laser(0);

    sf::RectangleShape line1(sf::Vector2f(laser1->longueur, laser1->largeur));
    line1.setFillColor(sf::Color(250, 50, 50));
    line1.rotate(laser1->angle);

    sf::RectangleShape line2(sf::Vector2f(laser2->longueur, laser2->largeur));
    line2.setFillColor(sf::Color(250, 50, 50));
    line2.rotate(laser2->angle);


    sf::CircleShape shape(support->rayon);
    //shape.setFillColor(sf::Color::Transparent);
    shape.setTexture(&texture2);
    shape.setTextureRect(sf::IntRect(300, 100, 1000, 1000));
    shape.setOrigin(support->rayon,support->rayon);

    //shape.setOutlineThickness(10);
    //shape.setOutlineColor(sf::Color(250, 50, 50));

    float x_laser_1 = support->x_laser_1;
    float y_laser_1 = support->y_laser_1;

    float x_laser_2 = support->x_laser_2;
    float y_laser_2 = support->y_laser_2;

    sf::CircleShape cer1(30);
    cer1.setFillColor(sf::Color(250, 50, 50));
    cer1.setOrigin(0,support->rayon);

    sf::CircleShape cer2(30);
    cer2.setFillColor(sf::Color(250, 50, 50));
    cer2.setOrigin(support->rayon,0);

    line1.setOrigin(laser1->longueur/2,0);
    line2.setOrigin(laser2->longueur/2,0);


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
        //support->move_line(&angle,AFlag, QFlag, &line1);
        //support->move_line(&angle,AFlag, QFlag, &line2);

        support->rotation_support(&angle, AFlag, QFlag, &shape);
        //support->move_cercle(&angle, AFlag, QFlag,&cer1 );
        //support->move_cercle(&angle, AFlag, QFlag,&cer2 );

        support->move_laser(&angle, AFlag, QFlag,&line1,&cer1);
        support->move_laser(&angle, AFlag, QFlag,&line2,&cer2);


        // Check screen boundaries
        if (x<0) x=0;
        if (x>((int)window.getSize().x)-20) x=((window.getSize().x)-20);
        if (y<0) y=0;
        if (y>((int)window.getSize().y)-20) y=((window.getSize().y)-20);

        window.clear();
        // Rotate and draw the sprite
        sprite.setTextureRect(rectSourceSprite);
        sprite.setPosition(x,y);
        shape.setPosition(support->x,support->y);
        line1.setPosition(support->x,support->y);
        line2.setPosition(support->x,support->y);

        cer1.setPosition(x_cer,y_cer);
        cer2.setPosition(x_cer,y_cer);

        window.draw(fond);
        window.draw(shape);
        window.draw(cer1);
        window.draw(cer2);
        window.draw(line1);
        window.draw(line2);
        window.draw(sprite);
        window.display();
      }

    return 0;
}
