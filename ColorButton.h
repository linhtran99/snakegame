#ifndef _COLORBUTTON_
#define _COLORBUTTON_
#include <iostream>
using namespace std;
#include "Color.h"

class ColorButton {
  int x, y;
  Color color;
  const int width = 40;
  const int height = 20;
 public:
  ColorButton (int a, int b, Color c);
  Color getColor (void) {return color;}
  void draw();
};

#endif
