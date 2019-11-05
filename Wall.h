#ifndef _Wall_
#define _Wall_
#include <iostream>
using namespace std;

class Wall {
 protected:
  unsigned int x;
  unsigned int y;
  const int width=20;
  const int height=20;
 public:
  Wall();
  Wall(unsigned int a, unsigned int b);
  unsigned int getX() const {return x;}
  unsigned int getY() const {return y;}
  void set_location(int a, int b);
  void draw();
};

#endif
