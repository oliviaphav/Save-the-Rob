#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "jeu.hpp"

//Namespace
using namespace sf;
using namespace std;


int main()
{
  Jeu* jeu = new Jeu();
  jeu->run();
    return 0;
}
