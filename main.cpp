#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "jeu.hpp"

#define SPRITE_SPEED 1

//Namespace
using namespace sf;
using namespace std;


int main()
{
  Jeu* jeu = new Jeu();
  jeu->run();

    return 0;
}

// git add arme.hpp catch.hpp entite.hpp jeu.cpp jeu.hpp joueur.hpp laser.cpp laser.hpp main.cpp Makefile mur.cpp mur.hpp obstacle.hpp porte_arme.cpp porte_arme.hpp robot.cpp robot.hpp support.cpp support.hpp tests_catch_laser.cpp tests_catch_mur.cpp tests_catch_porte_arme.cpp tests_catch_robot.cpp tests_catch_support.cpp
