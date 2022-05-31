#include "catch.hpp"
#include "arme.hpp"
#include "laser.hpp"

#define DECALAGE 400
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT (VideoMode::getDesktopMode().height - DECALAGE) //Hauteur de l'écran


TEST_CASE( "Tests classe Laser", "[laser]" ) {
  Laser l1;
  RectangleShape r1,r2;
  Laser l2(90,50,20,&r2);

  SECTION("Tests contructeurs")
  {
    REQUIRE(l1.getAngle() == 0);
    REQUIRE(l1.getLongueur() == WINDOW_HEIGHT/2);
    REQUIRE(l1.getLargeur() == 10);
    REQUIRE(l1.getEtat() == false);

    REQUIRE(l2.getAngle() == 90);
    REQUIRE(l2.getLongueur() == 50);
    REQUIRE(l2.getLargeur() == 20);
    REQUIRE(l2.getEtat() == false);
    REQUIRE(l2.getShape() == &r2);

    l1.setLongueur(30);
    REQUIRE(l1.getLongueur() == 30);
    l1.setAngle(70);
    REQUIRE(l1.getAngle() == 70);
    l1.setLargeur(50);
    REQUIRE(l1.getLargeur() == 50);
    l1.setShape(&r1);
    REQUIRE(l1.getShape() == &r1);
    l1.setEtat(true);
    REQUIRE(l1.getEtat() == true);
  }
}
