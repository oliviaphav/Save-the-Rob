#include "catch.hpp"
#include "support.hpp"
#include "obstacle.hpp"
#include "porte_arme.hpp"
#include "laser.hpp"
#include "arme.hpp"

#define DECALAGE 400
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT (VideoMode::getDesktopMode().height - DECALAGE) //Hauteur de l'écran


TEST_CASE( "Test classe Support", "[support]" ) {

    Support supp1;
    Texture t;
    CircleShape s;
    RectangleShape r1,r2;
    Laser *a1 = nullptr;
    Laser *a2 = nullptr;
    Support supp2(WINDOW_WIDTH/2,WINDOW_HEIGHT/2,1,&s,&t,&r1,&r2,a1,a2);

    SECTION("Tests contructeurs")
    {
      REQUIRE(supp1.getX() == 0);
      REQUIRE(supp1.getY() == 0);
      REQUIRE(supp1.getAngle() == 0);
      REQUIRE(supp1.getVitesse() == 0);
      REQUIRE(supp1.getLife() == true);
      REQUIRE(supp1.getRayon() == 10);

      REQUIRE(supp2.getX() == WINDOW_WIDTH/2);
      REQUIRE(supp2.getY() == WINDOW_HEIGHT/2);
      REQUIRE(supp2.getAngle() == 1);
      REQUIRE(supp2.getVitesse() == 0.2f);
      REQUIRE(supp2.getLife() == true);
      REQUIRE(supp2.getRayon() == WINDOW_HEIGHT/2);

      Porte_arme *PL1 =nullptr;
      supp2.setPorteArme1(PL1);
      REQUIRE(supp2.getPorteArme1()== PL1);
      //supp2.getPorteArme1()->setArme(a1);
      //REQUIRE(supp2.getPorteArme1()->getArme()==a1);
    }


    SECTION("Rotation sens horaire")
    {
      supp2.deplacement(true,false);
      REQUIRE(supp2.getAngle() == 0.2f);
    }

    SECTION("Rotation sens anti horaire")
    {
      supp2.deplacement(false,true);
      REQUIRE(supp2.getAngle() == -0.2f);
    }

    SECTION("On/Off Lasers")
    {

      //supp2.getPorteArme1()->getArme()->setEtat(false);
      //supp2.on_off(true,false);
      //REQUIRE(supp2.getPorteArme1()->getArme()->getEtat()==true);

    }

}
