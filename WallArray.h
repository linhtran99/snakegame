#ifndef _WallArray_
#define _WallArray_
#include <iostream>
#include "Wall.h"
using namespace std;

class WallArray {
 protected:
  int len;
  int width;
  int height;
  Wall* arr;
 public:
  WallArray() {
    width=50; height=40; len=2*width+2*height;
    int a=(1480-width*20)/2;
    int b=(1000-height*20)/2;
    arr=new Wall[len];
    for (int i=0; i<width; i++) {
      arr[i].set_location(a+20*i, b);
      arr[i+width].set_location(a+20*i, 980-b);
    }
    for (int i=0; i<height; i++) {
      arr[i+2*width].set_location(a, b+i*20);
      arr[i+2*width+height].set_location(1480-a, b+i*20);
    }
  }  
  
  WallArray(int l) {
    len=l;
    arr=new Wall[len];}

  void deleteWallArray() {
    delete[] arr;
    len=0; width=0; height=0;
  }
  
  int getLen() const {return len;}
  int getWidth() const {return width;}
  int getHeight() const {return height;}
  void draw();
  void setSize(int x, int y);
  void randomize(WallArray &arr);
  Wall &operator[] (int i);
};

#endif
