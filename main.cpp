#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "robot.hpp"


#define SPRITE_SPEED 1

int main()
{
    sf::RenderWindow window(sf::VideoMode(2000, 2000), "Save the Rob !");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    sf::Texture texture;
    if (!texture.loadFromFile("ressources/fond.jpg"))
      return -1;

    sf::Texture texture1;
    if (!texture1.loadFromFile("ressources/robot.png"))
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

    // Flags for key pressed
    bool upFlag=false;
    bool downFlag=false;
    bool leftFlag=false;
    bool rightFlag=false;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // If a key is pressed
          if (event.type == sf::Event::KeyPressed)
          {
              switch (event.key.code)
              {
              // If escape is pressed, close the application
              case  sf::Keyboard::Escape : window.close(); break;

              // Process the up, down, left and right keys
              case sf::Keyboard::Up :     upFlag=true; break;
              case sf::Keyboard::Down:    downFlag=true; break;
              case sf::Keyboard::Left:    leftFlag=true; break;
              case sf::Keyboard::Right:   rightFlag=true; break;
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
                default : break;
                }
            }

        // Update coordinates
        /*if (leftFlag)
        {
          x-=SPRITE_SPEED;
          rectSourceSprite.left=0;
          rectSourceSprite.top=0;

        }
        if (rightFlag)
        {
          x+=SPRITE_SPEED;
          rectSourceSprite.left=128;
          rectSourceSprite.top=98;
        }
        if (upFlag)
        {
          y-=SPRITE_SPEED;
          rectSourceSprite.left=0;
          rectSourceSprite.top=98;
        }

        if (downFlag)
        {
          y+=SPRITE_SPEED;
          rectSourceSprite.left=0;
          rectSourceSprite.top=98;

        }*/

        move(&x,&y,upFlag,downFlag,leftFlag,rightFlag,&rectSourceSprite);

        // Check screen boundaries
        if (x<0) x=0;
        if (x>(int)window.getSize().x) x=window.getSize().x;
        if (y<0) y=0;
        if (y>(int)window.getSize().y) y=window.getSize().y;

        window.clear();
        // Rotate and draw the sprite
        sprite.setTextureRect(rectSourceSprite);
        sprite.setPosition(x,y);

        window.draw(fond);
        window.draw(sprite);
        window.display();
      }

    return 0;
}
