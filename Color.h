#ifndef _COLOR_
#define _COLOR_
#include <iostream>
using namespace std;

class Color {
 public:
  double red, green, blue;
  Color () {
    red=0.;
    green=0.;
    blue=0.;
}
  Color (double a, double b, double c) {
    red=a;
    green=b;
    blue=c;
  }
  Color &operator = (const Color& c) {
    red = c.red;
    green = c.green;
    blue = c.blue;
    return *this;
  }
};

#endif
