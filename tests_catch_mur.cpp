#include "catch.hpp"
#include "obstacle.hpp"
#include "mur.hpp"

#define DECALAGE 400
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT (VideoMode::getDesktopMode().height - DECALAGE) //Hauteur de l'écran


TEST_CASE( "Tests classe Mur", "[mur]" ) {
  Mur mur1;
  CircleShape c1,c2;
  Mur mur2(WINDOW_WIDTH/2,WINDOW_HEIGHT/2,&c2);

  SECTION("Tests contructeurs")
  {
    REQUIRE(mur1.getX() == 0);
    REQUIRE(mur1.getY() == 0);
    REQUIRE(mur1.getRayon() == WINDOW_HEIGHT/2);
    mur1.setShape(&c1);
    REQUIRE(mur1.getShape() == &c1);

    REQUIRE(mur2.getX() == WINDOW_WIDTH/2);
    REQUIRE(mur2.getY() == WINDOW_HEIGHT/2);
    REQUIRE(mur2.getRayon() == WINDOW_HEIGHT/2);
    REQUIRE(mur2.getShape() == &c2);
  }
}
