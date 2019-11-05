#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
#include <cstdlib>
#include "Snake.h"
#include "Body.h"
#include "Wall.h"
#include "WallArray.h"
#include "Food.h"
#include "Color.h"
using namespace std;

void Food::location (Snake head, Body body, WallArray Obstacle) {
  for (unsigned int i=0; i<body.getSize(); i++) {
    for (int j=0; j<Obstacle.getLen(); j++) {
      while ((x == head.getX() && y == head.getY()) || (x == body.getX(i) && y == body.getY(i)) || (x == Obstacle[j].getX() && y == Obstacle[j].getY()) || x<260 || y<120 || x>1220 || y>860) {
	  x = 20*(rand()%75);
	  y = 20*(rand()%50);
      }
    }
  }
}

/* Set Color method */
void Food::setColor (double a, double b, double c) {
  color.red = a;
  color.green = b;
  color.blue = c;
}

void Food::draw() {
  glColor3f(1., 0., 0.);
  glBegin(GL_POLYGON);
  glVertex2f(x,y);
  glVertex2f(x + width, y);  
  glVertex2f(x + width, y + height);
  glVertex2f(x, y + height);
  glEnd();

}
