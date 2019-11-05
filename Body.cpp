#include "Body.h"
using namespace std;

// The constructor only needs to make sure we know what the head is.  Everything else is dynamic.
Body::Body(Snake& head0){
  head = &head0;
  size = 0;
}

// Draw calls the Snake draw function.  The body pieces are identical to the head, so this is fine.
void Body::draw(){
  if(size != 0){
    for(unsigned int i = 0; i < size; i++){
      body[i]->setColor(head->getColor());
      body[i]->draw();
    }
  }
}

// The body is a vector of dynamically added Snakes.
/* This function gets the direction the head is facing in, and adds a new 
   Snake to the vector at the correct location. */
void Body::add_body(direction facing){
  if (size == 0){  
    switch(facing){
    case UP:
      body.push_back(new Snake(head->getX(), head->getY() - 20));
    break;
    case DOWN:
      body.push_back(new Snake(head->getX(), head->getY() + 20));
    break;
    case LEFT:
      body.push_back(new Snake(head->getX() + 20, head->getY()));
    break;
    case RIGHT:
      body.push_back(new Snake(head->getX() - 20, head->getY()));
    break;
    }
  }
  else if (size == 1){
    switch(facing){
    case UP:
      body.push_back(new Snake(body.back()->getX(), body.back()->getY() - 20));
    break;
    case DOWN:
      body.push_back(new Snake(body.back()->getX(), body.back()->getY() + 20));
    break;
    case LEFT:
      body.push_back(new Snake(body.back()->getX() + 20, body.back()->getY()));
    break;
    case RIGHT:
      body.push_back(new Snake(body.back()->getX() - 20, body.back()->getY()));
    break;
    }
  }
  else{
    if(body.back()->getY() < body[body.size() - 2]->getY())
      body.push_back(new Snake(body.back()->getX(), body.back()->getY() - 20));

    else if(body.back()->getY() > body[body.size() - 2]->getY())
      body.push_back(new Snake(body.back()->getX(), body.back()->getY() + 20));

    else if(body.back()->getX() > body[body.size() - 2]->getX())
      body.push_back(new Snake(body.back()->getX() + 20, body.back()->getY()));

    else if(body.back()->getX() < body[body.size() - 2]->getX())
      body.push_back(new Snake(body.back()->getX() - 20, body.back()->getY()));
  }
  size++;
}


void Body::follow(){
  if(size != 0){
    for(unsigned int i = size -1; i > 0; i--){
      body[i]->setX(body[i - 1] -> getX());
      body[i]->setY(body[i - 1] -> getY());
    }
    body[0]->setX(head->getX());
    body[0]->setY(head->getY());
  }
}

bool Body::hitBodyCheck(){
  for(unsigned int i = 0; i < size; i++){
    if(body[i]->getX() == head->getX() && body[i]->getY() == head->getY())
      return true;
  }
  return false;
}

void Body::deleteBody(){
  body.erase(body.begin(), body.end());
  size = 0;
}
