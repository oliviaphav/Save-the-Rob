#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
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
#include <ctime>
#include <string>
#include "timer.hpp"

#define DECALAGE 400
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT (VideoMode::getDesktopMode().height - DECALAGE)  //Hauteur de l'écran


void Jeu::run()
{
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Save the Rob !");
    // Centre coordinates
    const int x=WINDOW_WIDTH/2;
    const int y=WINDOW_HEIGHT/2;

    //Mise en place des textures
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

    Texture texture2;
    if (!texture2.loadFromFile("ressources/support.jpg"))
      return;
    texture2.setSmooth(true);

    Font font;
    if(!font.loadFromFile("ressources/poppins.ttf"))
      return;

    SoundBuffer buffer;
    if (!buffer.loadFromFile("ressources/choc.wav"))
      return ;
    Sound sound_choc;
    sound_choc.setBuffer(buffer);

    IntRect rectSourceSprite(0,0,54,50);
    Sprite sprite(texture1,rectSourceSprite);
    sprite.setScale(3.f, 3.f);

    Text final_text;
    settings_text(&final_text,&font, WINDOW_WIDTH/15, WINDOW_HEIGHT/3);
    Text text_armure;
    settings_text(&text_armure,&font, WINDOW_WIDTH/30,WINDOW_HEIGHT/8);

    Clock clock;
    Clock armure_clock;
    Text time;

    // Creation d'objets
    Robot* rob = new Robot(x,y,1, &sprite , &texture1);

    CircleShape shape_support((WINDOW_HEIGHT/2));
    RectangleShape cube1(Vector2f(50, 50));
    RectangleShape cube2(Vector2f(50, 50));

    RectangleShape line1(Vector2f(WINDOW_HEIGHT, 10));
    Laser* laser1=new Laser(0,WINDOW_HEIGHT,10,&line1);

    RectangleShape line2(Vector2f(WINDOW_HEIGHT, 10));
    Laser* laser2=new Laser(90,WINDOW_HEIGHT,10,&line2);

    laser1->settings();
    laser2->settings();

    Support* support = new Support(x,y,0,&shape_support,&texture2,&cube1,&cube2,laser1,laser2);

    CircleShape shape_mur((WINDOW_HEIGHT/2));
    Mur* mur = new Mur(x,y,&shape_mur);

    Timer *t1 = new Timer(1,0);

    // Flags for key pressed
    bool upFlag=false;
    bool downFlag=false;
    bool leftFlag=false;
    bool rightFlag=false;
    bool AFlag=false;
    bool QFlag=false;
    bool Flag1=false;
    bool Flag2=false;
    bool SpaceFlag=false;

    while (window.isOpen())
    {
      FloatRect boundingBox = sprite.getGlobalBounds();
      if(rob->getLife()==false || support->getLife()==false)
        end=true;

        clavier(&upFlag,&downFlag,&leftFlag,&rightFlag,&AFlag, &QFlag, &Flag1,&Flag2,&SpaceFlag, window);

        support->on_off(Flag1,Flag2);


        if(end==false)
        {
          t1->chrono(&clock, &time, &font);

          if(t1->getMin()<=0 && t1->getSec()<=0)
            support->setLife(false);

          rob->deplacement(upFlag,downFlag,leftFlag,rightFlag,&rectSourceSprite);
          rob->activation_armure(SpaceFlag,&armure_clock,&rectSourceSprite,&text_armure);

         if(support->getPorteArme1()->getArme()->getEtat()==true && rob->getArmure()==false)
          rob->collision(&boundingBox,&line1,&rectSourceSprite);

         if(support->getPorteArme2()->getArme()->getEtat()==true && rob->getArmure()==false)
          rob->collision(&boundingBox,&line2,&rectSourceSprite);



          support->deplacement(AFlag, QFlag);

          rob->settings();
          support->settings();
          mur->settings();
          sprite.setTextureRect(rectSourceSprite);

          if(rob->getLife()==false)
            sound_choc.play();
        }

          window.clear();

          if(rob->getLife()==false)
            final_text.setString("Game Over \nPlayer 1 wins \nPlayer 2 loses");

          if(support->getLife()==false)
            final_text.setString("Time Out \nPlayer 1 loses \nPlayer 2 wins");


          window.draw(fond);
          window.draw(shape_support);
          window.draw(time);
          window.draw(shape_mur);
          window.draw(cube1);
          window.draw(cube2);
          window.draw(text_armure);

          if(support->getPorteArme1()->getArme()->getEtat()==true)
            window.draw(line1);
          if(support->getPorteArme2()->getArme()->getEtat()==true)
            window.draw(line2);

          window.draw(final_text);
          window.draw(sprite);
          window.draw(shape_mur);
          window.display();
  }

  delete rob;
  delete support;
  /*delete laser1;
  delete laser2;*/
  delete mur;
  delete t1;
}

void Jeu::clavier(bool *upFlag, bool *downFlag, bool *leftFlag, bool *rightFlag,bool *AFlag, bool *QFlag,bool *Flag1, bool *Flag2,bool *SpaceFlag,RenderWindow &window)
{
  Event event;
  while (window.pollEvent(event))
  {
      if (event.type == Event::Closed)
          window.close();

  // Touche pressée
    if (event.type == Event::KeyPressed)
    {
        switch (event.key.code)
        {
        // Fermeture de la fenetre
        case  Keyboard::Escape : window.close(); break;

        case Keyboard::Up :     *upFlag=true;break;
        case Keyboard::Down:    *downFlag=true;break;
        case Keyboard::Left:    *leftFlag=true; break;
        case Keyboard::Right:   *rightFlag=true; break;
        case Keyboard::Num1:     *Flag1=true;break;
        case Keyboard::Num2:     *Flag2=true; break;
        case Keyboard::A:       *AFlag=true;break;
        case Keyboard::Q:       *QFlag=true; break;
        case Keyboard::Space:    *SpaceFlag=true; break;
        default : break;
        }
    }


  // Touche relachée
      if (event.type == Event::KeyReleased)
      {
          switch (event.key.code)
          {
          case Keyboard::Up :     *upFlag=false; break;
          case Keyboard::Down:    *downFlag=false; break;
          case Keyboard::Left:    *leftFlag=false; break;
          case Keyboard::Right:   *rightFlag=false; break;
          case Keyboard::Num1:     *Flag1=false;break;
          case Keyboard::Num2:     *Flag2=false; break;
          case Keyboard::A:       *AFlag=false; break;
          case Keyboard::Q:       *QFlag=false; break;
          case Keyboard::Space:    *SpaceFlag=false; break;
          default : break;
          }
      }
    }

}

void Jeu::settings_text(Text* text, Font* font, float x, float y)
{
  text->setFont(*font);
  text->setCharacterSize(60);
  text->setFillColor(Color::White);
  text->setOrigin(text->getLocalBounds().width/2. , text->getLocalBounds().height/2.);
  text->setPosition(x , y);
}
