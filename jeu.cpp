#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "jeu.hpp"

#define DECALAGE 50
#define WINDOW_WIDTH sf::VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT sf::VideoMode::getDesktopMode().height - DECALAGE //Hauteur de l'écran


/*void Jeu::initFenetre()
{
    this->window = new sf::RenderWindow (sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Save the Rob !");
}*/

void Jeu::clavier(bool *upFlag, bool *downFlag, bool *leftFlag, bool *rightFlag,bool *AFlag, bool *QFlag, sf::RenderWindow &window)
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
        case sf::Keyboard::Up :     *upFlag=true;break;
        case sf::Keyboard::Down:    *downFlag=true;break;
        case sf::Keyboard::Left:    *leftFlag=true; break;
        case sf::Keyboard::Right:   *rightFlag=true; break;
        case sf::Keyboard::A:       *AFlag=true;break;
        case sf::Keyboard::Q:       *QFlag=true; break;
        default : break;
        }
    }


  // If a key is released
      if (event.type == sf::Event::KeyReleased)
      {
          switch (event.key.code)
          {
          // Process the up, down, left and right keys
          case sf::Keyboard::Up :     *upFlag=false; break;
          case sf::Keyboard::Down:    *downFlag=false; break;
          case sf::Keyboard::Left:    *leftFlag=false; break;
          case sf::Keyboard::Right:   *rightFlag=false; break;
          case sf::Keyboard::A:       *AFlag=false; break;
          case sf::Keyboard::Q:       *QFlag=false; break;
          default : break;
          }
      }
    }

}
