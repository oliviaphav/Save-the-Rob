#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "robot.hpp"
#include <SFML/Window/Keyboard.hpp>


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

    sf::CircleShape shape(750);
    shape.setFillColor(sf::Color::Transparent);

    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color(250, 150, 100));




    // Sprite coordinates
    int x=window.getSize().x/2.;
    int y=window.getSize().y/2.;

    // Flags for key pressed
    bool upFlag=false;
    bool downFlag=false;
    bool leftFlag=false;
    bool rightFlag=false;
    bool AFlag=false;
    bool QFlag=false;

    int angle=0;
    Robot* rob = new Robot();

    sf::RectangleShape line(sf::Vector2f(150, 5));
    //line.rotate(angle);


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
              case sf::Keyboard::Up :     upFlag=true; printf("Up\n");break;
              case sf::Keyboard::Down:    downFlag=true; printf("Down\n");break;
              case sf::Keyboard::Left:    leftFlag=true; break;
              case sf::Keyboard::Right:   rightFlag=true; break;
              case sf::Keyboard::A:       AFlag=true; printf("A\n");break;
              //case sf::Keyboard::Q:       QFlag=true; break;
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
                //case sf::Keyboard::Q:       QFlag=false; break;
                default : break;
                }
            }

        rob->move(&x,&y,upFlag,downFlag,leftFlag,rightFlag,&rectSourceSprite);
        rob->move_line(&angle,AFlag, QFlag, &line);


        // Check screen boundaries
        if (x<0) x=0;
        if (x>((int)window.getSize().x)-20) x=((window.getSize().x)-20);
        if (y<0) y=0;
        if (y>((int)window.getSize().y)-20) y=((window.getSize().y)-20);

        window.clear();
        // Rotate and draw the sprite
        sprite.setTextureRect(rectSourceSprite);
        sprite.setPosition(x,y);
        shape.setPosition(300,50);
        line.setPosition(50,50);

        window.draw(fond);
        window.draw(sprite);
        window.draw(shape);
        window.draw(line);
        window.display();
      }

    return 0;
}
