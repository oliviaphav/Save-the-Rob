#include "catch.hpp"
#include "obstacle.hpp"
#include "porte_arme.hpp"
#include "laser.hpp"
#include "arme.hpp"

#define DECALAGE 400
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT (VideoMode::getDesktopMode().height - DECALAGE) //Hauteur de l'écran


TEST_CASE( "Tests classe Porte arme", "[porte_arme]" ) {
  Porte_arme PL1;

  RectangleShape r1; Laser* a1;

  RectangleShape r2; Laser* a2;
  Porte_arme PL2(1,1,&r2,a2);

  SECTION("Tests contructeurs")
  {
    REQUIRE(PL1.getX() == 0);
    REQUIRE(PL1.getY() == 0);
    PL1.setShape(&r1);
    REQUIRE(PL1.getShape() == &r1);
    PL1.setArme(a1);
    REQUIRE(PL1.getArme() == a1);

    REQUIRE(PL2.getX() == 1);
    REQUIRE(PL2.getY() == 1);
    REQUIRE(PL2.getShape() == &r2);
    REQUIRE(PL2.getArme() == a2);
  }
}
