#ifndef _SNAKE_
#define _SNAKE_
#include "Color.h"
#include <iostream>
using namespace std;

enum direction{UP, DOWN, LEFT, RIGHT,};

class Snake{
  unsigned int x;
  unsigned int y;
  const int height = 20;
  const int width = 20;
  Color color;
 public:
  Snake();
  Snake(unsigned int a, unsigned int b);
  unsigned int getX() const {return x;}
  unsigned int getY() const {return y;}
  void setX(int x0){x = x0;}
  void setY(int y0){y = y0;}
  void setColor (Color c);
  Color getColor () {return color;}
  void draw ();
  void moveUp(int);
  void moveDown(int);
  void moveLeft(int);
  void moveRight(int);
};

#endif
