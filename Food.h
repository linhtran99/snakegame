#ifndef _FOOD_
#define _FOOD_
#include <iostream>
using namespace std;
#include "WallArray.h"
#include "Wall.h"
#include "Color.h"

int rand();

class Food {
 protected:
  unsigned int x, y;
  const int height = 20;
  const int width = 20;
  Color color;
 public:
  Food() {
    x = 300;
    y = 200;
  }
  void setColor (double a, double b, double c);
  unsigned int getX() {return x;}
  unsigned int getY() {return y;} 
  void location (Snake head, Body body, WallArray Obstacle);
  void draw();
};

#endif
