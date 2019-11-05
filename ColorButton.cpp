#include <iostream>
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include "ColorButton.h"
#include "Color.h"
using namespace std;

ColorButton::ColorButton (int a, int b, Color c) {
  x=a;
  y=b;
  color.red = c.red;
  color.green = c.green;
  color.blue = c.blue;
}

void ColorButton::draw () {
  glColor3f(color.red, color.green, color.blue);
  glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
  glEnd();
}

