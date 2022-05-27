#ifndef JEU_HPP
#define JEU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace sf;
using namespace std;

class Jeu {

  public :
    Jeu(){
      end=false;
    };

    void run();
    void clavier(bool *upFlag, bool *downFlag, bool *leftFlag, bool *rightFlag,bool *AFlag, bool *QFlag,bool *Flag1, bool *Flag2, RenderWindow &window);

  protected :
  bool end;

  };




#endif
