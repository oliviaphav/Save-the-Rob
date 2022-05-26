#ifndef JEU_HPP
#define JEU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Jeu {

  public :
    Jeu(){};
    //sf::RenderWindow *window;
    //void initFenetre();
    void clavier(bool *upFlag, bool *downFlag, bool *leftFlag, bool *rightFlag,bool *AFlag, bool *QFlag,bool *Flag1, bool *Flag2, sf::RenderWindow &window);

  };



#endif
