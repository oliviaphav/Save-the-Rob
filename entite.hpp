#ifndef ENTITE_HPP
#define ENTITE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace sf;
using namespace std;

class Entite {

  public :
  virtual ~Entite()=default;
    virtual void settings() const=0;

};


#endif
