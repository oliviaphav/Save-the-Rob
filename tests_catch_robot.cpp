
#define CATCH_CONFIG_MAIN // Must only appear in ONE test file
#include "catch.hpp"
#include "robot.hpp"

#define DECALAGE 400
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT (VideoMode::getDesktopMode().height - DECALAGE) //Hauteur de l'écran


TEST_CASE( "Tests classe Robot ", "[robot]" ) {

    Robot rob1;
    Texture t;
    Sprite s;
    Sprite s1;
    Robot rob2(1,1,1,&s,&t);

  SECTION("Tests constructeurs")
  {
    REQUIRE(rob1.getX() == 0);
    REQUIRE(rob1.getY() == 0);
    REQUIRE(rob1.getVitesse() == 1);

    REQUIRE(rob2.getX() == 1);
    REQUIRE(rob2.getY() == 1);
    REQUIRE(rob2.getVitesse() == 1);

    REQUIRE(rob2.getSprite()==&s);
    rob2.setSprite(&s1);
    REQUIRE(rob2.getSprite()==&s1);
  }

  }

TEST_CASE( "Deplacement robot ","[robot]") {
  Texture t;
  IntRect R3(0,0,50,50);
  Sprite s;
  Robot rob(WINDOW_WIDTH/2,WINDOW_HEIGHT/2,1,&s,&t);

  SECTION("Pas de deplacement")
  {
    rob.deplacement(false,false,false,false,&R3);
    REQUIRE(rob.getX() == WINDOW_WIDTH/2 );
    REQUIRE(rob.getY() == WINDOW_HEIGHT/2);
  }


  SECTION("Deplacement a gauche")
  {
    rob.deplacement(false,false,true,false,&R3);
    REQUIRE(rob.getX() == WINDOW_WIDTH/2 - 1);
    REQUIRE(rob.getY() == WINDOW_HEIGHT/2);
  }

  SECTION("Deplacement a droite")
  {
    rob.deplacement(false,false,false,true,&R3);
    REQUIRE(rob.getX() == WINDOW_WIDTH/2 + 1);
    REQUIRE(rob.getY() == WINDOW_HEIGHT/2);
  }

  SECTION("Deplacement en haut")
  {
    rob.deplacement(true,false,false,false,&R3);
    REQUIRE(rob.getX() == WINDOW_WIDTH/2);
    REQUIRE(rob.getY() == WINDOW_HEIGHT/2 - 1);
  }

  SECTION("Deplacement en bas")
  {
    rob.deplacement(false,true,false,false,&R3);
    REQUIRE(rob.getX() == WINDOW_WIDTH/2);
    REQUIRE(rob.getY() == WINDOW_HEIGHT/2 + 1);
  }


}

TEST_CASE( "Collision robot laser ","[robot]") {

    Texture t;
    Sprite s;
    Robot rob2(1,1,1,&s,&t);
    Point p1; p1.x=1;p1.y=0;
    Point p2; p2.x=2;p2.y=0;
    Point p3; p3.x=3;p3.y=0;

    REQUIRE(rob2.onSegment(p1,p2,p3) == true);

    SECTION("Orientation") {

      Point p4; p4.x=2;p4.y=2;
      Point p5; p5.x=2;p5.y=-2;

      REQUIRE(rob2.orientation(p1,p2,p3) == 0);
      REQUIRE(rob2.orientation(p1,p2,p4) == 2);
      REQUIRE(rob2.orientation(p1,p2,p5) == 1);
      }

    SECTION("Intersection") {

      Point p4; p4.x=2;p4.y=2;

      REQUIRE(rob2.doIntersect(p1,p2,p3,p4) == false);
      REQUIRE(rob2.doIntersect(p1,p3,p2,p4) == true);
      }

    SECTION("Collision rectangles") {

      FloatRect R1; R1.left=0; R1.top=0; R1.width=10; R1.height=10;
      RectangleShape R2(Vector2f(10, 10));
      IntRect R3(0,0,50,50);
      rob2.collision(&R1,&R2,&R3);
      REQUIRE(rob2.getLife() == false); //Collision

      FloatRect R4; R4.left=50; R1.top=50; R1.width=10; R1.height=10;
      rob2.setLife(true);
      rob2.collision(&R4,&R2,&R3);
      REQUIRE(rob2.getLife() == true); //Pas de collision

        }

    }
