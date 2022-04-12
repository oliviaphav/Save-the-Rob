#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

void move(int* x, int* y, bool upFlag, bool downFlag, bool leftFlag, bool rightFlag, sf::IntRect* rectSourceSprite);

#endif
