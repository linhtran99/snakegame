#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#ifdef MACOSX
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
#include "Wall.h"
using namespace std;

Wall::Wall() {
  x=0;
  y=0;
}

Wall::Wall(unsigned int a, unsigned int b) {
  x=a;
  y=b;
}

void Wall::set_location(int a, int b) {
  x=a;
  y=b;
}

void Wall::draw() {
  glColor3f(1., 1., 1.);
  glBegin(GL_POLYGON);
  glVertex2f(x, y);
  glVertex2f(x, y+height);
  glVertex2f(x+width, y+height);
  glVertex2f(x+width, y);
  glEnd();
}
