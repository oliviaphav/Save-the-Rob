#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "jeu.hpp"

#define DECALAGE 50
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT VideoMode::getDesktopMode().height - DECALAGE //Hauteur de l'écran


/*void Jeu::initFenetre()
{
    this->window = new RenderWindow (VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Save the Rob !");
}*/

void Jeu::clavier(bool *upFlag, bool *downFlag, bool *leftFlag, bool *rightFlag,bool *AFlag, bool *QFlag,bool *Flag1, bool *Flag2, RenderWindow &window)
{
  Event event;
  while (window.pollEvent(event))
  {
      if (event.type == Event::Closed)
          window.close();

  // If a key is pressed
    if (event.type == Event::KeyPressed)
    {
        switch (event.key.code)
        {
        // If escape is pressed, close the application
        case  Keyboard::Escape : window.close(); break;

        // Process the up, down, left and right keys
        case Keyboard::Up :     *upFlag=true;break;
        case Keyboard::Down:    *downFlag=true;break;
        case Keyboard::Left:    *leftFlag=true; break;
        case Keyboard::Right:   *rightFlag=true; break;
        case Keyboard::Num1:       *Flag1=true; break;
        case Keyboard::Num2:       *Flag2=true; break;
        case Keyboard::A:       *AFlag=true;break;
        case Keyboard::Q:       *QFlag=true; break;
        default : break;
        }
    }


  // If a key is released
      if (event.type == Event::KeyReleased)
      {
          switch (event.key.code)
          {
          // Process the up, down, left and right keys
          case Keyboard::Up :     *upFlag=false; break;
          case Keyboard::Down:    *downFlag=false; break;
          case Keyboard::Left:    *leftFlag=false; break;
          case Keyboard::Right:   *rightFlag=false; break;
          case Keyboard::Num1:       *Flag1=false; break;
          case Keyboard::Num2:       *Flag2=false; break;
          case Keyboard::A:       *AFlag=false; break;
          case Keyboard::Q:       *QFlag=false; break;
          default : break;
          }
      }
    }

}
