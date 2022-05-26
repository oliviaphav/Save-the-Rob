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
#define DECALAGE 400
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT (VideoMode::getDesktopMode().height - DECALAGE)  //Hauteur de l'écran

//Namespace
using namespace sf;
using namespace std;


int main()
{
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Save the Rob !");
    Jeu* jeu = new Jeu();
    // Centre coordinates
    const int x=WINDOW_WIDTH/2;
    const int y=WINDOW_HEIGHT/2;
    cout<<window.getSize().x/2.<<endl; //1440
    cout<<window.getSize().y/2.<<endl; //741

    cout<<WINDOW_WIDTH/2<<endl;
    cout<<(WINDOW_HEIGHT/2)<<endl;

    Texture texture;
    if (!texture.loadFromFile("ressources/fond.jpg"))
      return -1;
    Sprite fond;
    fond.scale(3.f, 3.f);
    fond.setTexture(texture);


    Texture texture1;
    if (!texture1.loadFromFile("ressources/robot.png"))
      return -1;
    texture1.setSmooth(true);
    IntRect rectSourceSprite(0,0,54,50);
    Sprite sprite(texture1,rectSourceSprite);
    sprite.setTextureRect(rectSourceSprite);
    sprite.setScale(3.f, 3.f);
    Robot* rob = new Robot(x,y,1, &sprite , &texture1);


    Texture texture2;
    if (!texture2.loadFromFile("ressources/support.jpg"))
      return -1;
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
     cout<<"Erreur chargement font"<<endl;

    Text text;
    text.setFont(font);
    text.setString("Game Over \nPlayer 1 wins");
    text.setCharacterSize(60);
    text.setFillColor(Color::White);
    text.setOrigin(text.getLocalBounds().width/2. , text.getLocalBounds().height/2.);

    //cout << text.getLocalBounds().width << "\t" << text.getLocalBounds().height;


    // Flags for key pressed
    bool upFlag=false;
    bool downFlag=false;
    bool leftFlag=false;
    bool rightFlag=false;
    bool AFlag=false;
    bool QFlag=false;
    bool Flag1=false;
    bool Flag2=false;

    bool end=false;

    while (window.isOpen())
    {

      if(end==false)
      {
        jeu->clavier(&upFlag,&downFlag,&leftFlag,&rightFlag,&AFlag, &QFlag, &Flag1,&Flag2, window);

        FloatRect boundingBox = sprite.getGlobalBounds();

        support->on_off(Flag1,Flag2);

         rob->deplacement(upFlag,downFlag,leftFlag,rightFlag,&rectSourceSprite);
         if(support->PL1->arme->etat==true)
          rob->collision(&boundingBox,&line1);
         if(support->PL2->arme->etat==true)
          rob->collision(&boundingBox,&line2);
          support->deplacement(AFlag, QFlag);
      }



      window.clear();

      rob->settings();
      support->settings();
      mur->settings();

      if(rob->getLife()==false)
        end=true;

      window.draw(fond);
      window.draw(shape_support);
      window.draw(shape_mur);
      window.draw(sprite);
      window.draw(cube1);
      window.draw(cube2);
      if(support->PL1->arme->etat==true)
        window.draw(line1);
      if(support->PL2->arme->etat==true)
        window.draw(line2);
      if(rob->getLife()==false)
      {
        text.setPosition(window.getSize().x/8. , 100);
        window.draw(text);
      }
      window.display();

    }

    return 0;
}
