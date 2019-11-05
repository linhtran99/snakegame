#include <iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<stdlib.h>
#include<math.h>
#include "Snake.h"
#include "Color.h"
using namespace std;

/* Default constructor */
Snake::Snake () {
  x = 760;
  y = 500;
}

/* Constructor */
Snake::Snake (unsigned int a, unsigned int b) {
  x = a;
  y = b;
}

/* Set Color method */
void Snake::setColor (Color c) {
  color = c;
}

/* Drawing snake */
void Snake::draw () {
  glColor3f(color.red, color.green, color.blue);
  glBegin(GL_POLYGON);    
    glVertex2f(x,y);
    glVertex2f(x + width, y);  
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void Snake::moveUp(int d){
  y += d;
}

void Snake::moveDown(int d){
  y -= d;
}

void Snake::moveLeft(int d){
  x -= d;
}

void Snake::moveRight(int d){
  x += d;
}
