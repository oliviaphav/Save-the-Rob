#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <unistd.h>
#include <math.h>
#include "jeu.hpp"
#include "robot.hpp"
#include "entite.hpp"
#include "joueur.hpp"
#include "support.hpp"
#include "obstacle.hpp"
#include "mur.hpp"
#include "porte_arme.hpp"
#include "arme.hpp"
#include "laser.hpp"

#define DECALAGE 400
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT (VideoMode::getDesktopMode().height - DECALAGE)  //Hauteur de l'écran


void Jeu::run()
{
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Save the Rob !");
    // Centre coordinates
    const int x=WINDOW_WIDTH/2;
    const int y=WINDOW_HEIGHT/2;

    Texture texture;
    if (!texture.loadFromFile("ressources/fond.jpg"))
      return;
    Sprite fond;
    fond.scale(3.f, 3.f);
    fond.setTexture(texture);


    Texture texture1;
    if (!texture1.loadFromFile("ressources/robot.png"))
      return;
    texture1.setSmooth(true);
    IntRect rectSourceSprite(0,0,54,50);
    Sprite sprite(texture1,rectSourceSprite);
    sprite.setScale(3.f, 3.f);

    Robot* rob = new Robot(x,y,1, &sprite , &texture1);


    Texture texture2;
    if (!texture2.loadFromFile("ressources/support.jpg"))
      return;
    texture1.setSmooth(true);
    CircleShape shape_support((WINDOW_HEIGHT/2));
    RectangleShape cube1(Vector2f(50, 50));
    RectangleShape cube2(Vector2f(50, 50));

    RectangleShape line1(Vector2f(WINDOW_HEIGHT, 10));
    line1.setFillColor(Color(250, 50, 50));
    line1.rotate(90);
    Laser* laser1=new Laser(0,WINDOW_HEIGHT,10,&line1);

    RectangleShape line2(Vector2f(WINDOW_HEIGHT, 10));
    line2.setFillColor(Color(250, 50, 50));
    Laser* laser2=new Laser(90,WINDOW_HEIGHT,10,&line2);

    Support* support = new Support(x,y,0,&shape_support,&texture2,&cube1,&cube2,laser1,laser2);

    CircleShape shape_mur((WINDOW_HEIGHT/2));
    Mur* mur = new Mur(x,y,&shape_mur);

    Font font;
    if(!font.loadFromFile("ressources/poppins.ttf"))
     return;

     SoundBuffer buffer;
     if (!buffer.loadFromFile("ressources/choc.wav"))
      return ;
    Sound sound_choc;
    sound_choc.setBuffer(buffer);

    Text text;
    text.setFont(font);
    text.setString("Game Over \nPlayer 1 wins \nPlayer 2 loses");
    text.setCharacterSize(60);
    text.setFillColor(Color::White);
    text.setOrigin(text.getLocalBounds().width/2. , text.getLocalBounds().height/2.);


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
      FloatRect boundingBox = sprite.getGlobalBounds();
      if(rob->getLife()==false)
        end=true;
        clavier(&upFlag,&downFlag,&leftFlag,&rightFlag,&AFlag, &QFlag, &Flag1,&Flag2, window);
        support->on_off(Flag1,Flag2);


        if(end==false)
        {
         rob->deplacement(upFlag,downFlag,leftFlag,rightFlag,&rectSourceSprite);

         if(support->getPorteArme1()->getArme()->getEtat()==true)
          rob->collision(&boundingBox,&line1,&rectSourceSprite);

         if(support->getPorteArme2()->getArme()->getEtat()==true)
          rob->collision(&boundingBox,&line2,&rectSourceSprite);

          support->deplacement(AFlag, QFlag);

          rob->settings();
          support->settings();
          mur->settings();
          sprite.setTextureRect(rectSourceSprite);

          if(rob->getLife()==false)
          {
            sound_choc.play();
          }
        }

          window.clear();


          window.draw(fond);
          window.draw(shape_support);
          window.draw(shape_mur);
          window.draw(cube1);
          window.draw(cube2);

          if(support->getPorteArme1()->getArme()->getEtat()==true)
            window.draw(line1);
          if(support->getPorteArme2()->getArme()->getEtat()==true)
            window.draw(line2);
          if(rob->getLife()==false)
          {
            text.setPosition(WINDOW_WIDTH/8. , WINDOW_HEIGHT/2);
            window.draw(text);
          }
          window.draw(sprite);
          window.draw(shape_mur);
            window.display();
  }

}

void Jeu::clavier(bool *upFlag, bool *downFlag, bool *leftFlag, bool *rightFlag,bool *AFlag, bool *QFlag,bool *Flag1, bool *Flag2,RenderWindow &window)
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
        case Keyboard::Num1:     *Flag1=true;break;
        case Keyboard::Num2:     *Flag2=true; break;
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
          case Keyboard::Num1:     *Flag1=false;break;
          case Keyboard::Num2:     *Flag2=false; break;
          case Keyboard::A:       *AFlag=false; break;
          case Keyboard::Q:       *QFlag=false; break;
          default : break;
          }
      }
    }

}
