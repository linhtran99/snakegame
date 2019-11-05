#ifndef _BODY_
#define _BODY_
#include "Snake.h"
#include <vector>

class Body{
  std::vector<Snake*> body;
  Snake* head;
  unsigned int size;
 public:
  Body(Snake&);
  unsigned int getSize(){return size;}
  void follow();
  void draw();
  void add_body(direction);
  unsigned int getX(int n) {return body[n]->getX();}
  unsigned int getY(int n) {return body[n]->getY();}
  bool hitBodyCheck();
  void deleteBody();
};

#endif
