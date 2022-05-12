#ifndef POINT_HPP
#define POINT_HPP

class Point {
public:
  Point(): _x(0), _y(0){};
  Point(int x, int y) : _x(x), _y(y) {};

  const int& getX() const {return _x;};
  const int& getY() const {return _y;};
  int& getX() {return _x;};
  int& getY() {return _y;};

private:
  int _x;
  int _y;

};

#endif
