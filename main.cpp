#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "robot.hpp"
#include "support.hpp"
#include "laser.hpp"
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

    // Sprite coordinates
    int x=window.getSize().x/2.;
    int y=window.getSize().y/2.;

    int x_cer = window.getSize().x/2.;
    int y_cer = 2;



    // Flags for key pressed
    bool upFlag=false;
    bool downFlag=false;
    bool leftFlag=false;
    bool rightFlag=false;
    bool AFlag=false;
    bool QFlag=false;

    int angle=0;
    Robot* rob = new Robot();
    Support* support = new Support(window.getSize().x/2.,window.getSize().y/2.);
    Laser* laser1 = new Laser();

    sf::RectangleShape line(sf::Vector2f(laser1->longueur, laser1->largeur));
    line.rotate(laser1->angle);

    sf::CircleShape shape(support->rayon);
    //shape.setFillColor(sf::Color::Transparent);
    shape.setTexture(&texture2);
    shape.setTextureRect(sf::IntRect(300, 100, 1000, 1000));
    shape.setOrigin(support->rayon,support->rayon);

    //shape.setOutlineThickness(10);
    //shape.setOutlineColor(sf::Color(250, 50, 50));

    float x_laser_1 = support->x_laser_1;
    float y_laser_1 = support->y_laser_1;

    sf::CircleShape cer(30);
    cer.setFillColor(sf::Color(250, 50, 50));


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
        //support->move_line(&angle,AFlag, QFlag, &line);

        support->rotation_support(&angle, AFlag, QFlag, &shape);


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
        line.setPosition(x_laser_1,y_laser_1);

        cer.setPosition(x_cer,y_cer);

        window.draw(fond);
        window.draw(shape);
        window.draw(cer);
        window.draw(sprite);
        window.draw(line);
        window.display();
      }

    return 0;
}
