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
#include <time.h>
#include <math.h>
#include "WallArray.h"
using namespace std;

void WallArray::draw() {
  for (int i=0; i<len; i++) 
    arr[i].draw();
}

void WallArray::setSize(int w, int h) {
  width=w; height=h; len=2*w+2*h;
  int a=(1480-w*20)/2;
  int b=(1000-h*20)/2;
  arr=new Wall[len];
  for (int i=0; i<w; i++) {
    arr[i].set_location(a+20*i, b);
    arr[i+w].set_location(a+20*i, 980-b);
  }
  for (int i=0; i<h; i++) {
    arr[i+2*w].set_location(a, b+i*20);
    arr[i+2*w+h].set_location(1480-a, b+i*20);
  }
}

void WallArray::randomize(WallArray &border) {
  srand(time(NULL));
  len=(rand()%(border.getWidth()*border.getHeight()))/50;
  int a=(1480-border.getWidth()*20)/2;
  int b=(1000-border.getHeight()*20)/2;
  arr=new Wall[len];

  for (int i=0; i<len; i++) {
	arr[i].set_location(a+20*(rand()%border.getWidth()), b+20*(rand()%border.getHeight()));
  }
}


Wall &WallArray::operator[] (int i) {
  return arr[i];
}
