#include<iostream>
#include<iomanip>
#include<sstream>
using namespace std;
#include<vector>
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<stdlib.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#include <string>
#include "Snake.h"
#include "Body.h"
#include "Food.h"
#include "Wall.h"
#include "WallArray.h"
#include "initvals.h"
#include "ColorButton.h"
#include "Color.h"
#include "texture.h"

Snake head;
Body snakeBody(head);
Food apple;
WallArray wall, Obs;
ColorButton c1(1800, 800, color1), c2(1800, 760, color2), c3(1800, 720, color3), c4(1800, 680, color4), c5(1800, 640, color5), c6(1800, 600, color6);

void food_spawn() {
  if (head.getX() == apple.getX() && head.getY() == apple.getY()) {
    snakeBody.add_body(arrows);
    score++;
    if (score%10==0 && score<80)
      speed -=20;
    Obs.randomize(wall);
    for (unsigned int i=0; i<snakeBody.getSize(); i++)
      apple.location(head, snakeBody, Obs);
    drawTexture(appleT, apple.getX() + 20, apple.getY() + 20, -20, -20);
  }
  else
    drawTexture(appleT, apple.getX() + 20, apple.getY() + 20, -20, -20);
}

void ColorButtonDraw() {
  c1.draw();
  c2.draw();
  c3.draw();
  c4.draw();
  c5.draw();
  c6.draw();

  glRasterPos2f(1740, 860);
  glColor3f(1., 1., 1.);
  for (int i = 0; i < colorlen; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, colorChoice[i]);
  for (int i=0; i<6; i++) {
    glRasterPos2f(1780, 805-i*40);
    glColor3f(1., 1., 1.);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, colornum[i]);
  }
}

void ScoreDraw() {
  glRasterPos2f(1520, 950);
  glColor3f(1., 1., 1.);
  for (int i = 0; i < scorestr; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreDisplay[i]);

  int len;
  char buffer[10];
  len = sprintf(buffer, "%d", score);
  glRasterPos2f(1620, 950);
  glColor3f(1., 1., 1.);
  for (int i = 0; i < len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, buffer[i]);
}

void display() {
  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);
  drawTexture(backgroundT, 0, 0, 1920, 1080);
  ScoreDraw();

  switch (currentGameMode){
  case PLAY:
    head.setColor(current_color);
    head.draw();
    food_spawn();
    snakeBody.draw();
    wall.draw();
    Obs.draw();
    ColorButtonDraw();

    break;
  case OVER:
    glRasterPos2f(750, 500);
    glColor3f(1., 1., 1.);
    for (int i = 0; i < endMessageSize1; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, gameEndMessage1[i]);

    glRasterPos2f(750, 450);
    glColor3f(1., 1., 1.);
    for (int i = 0; i < endMessageSize2; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, gameEndMessage2[i]);
    break;

  case PAUSE:
    head.setColor(current_color);
    head.draw();
    food_spawn();
    snakeBody.draw();
    wall.draw();
    Obs.draw();
    ColorButtonDraw();

    glRasterPos2f(700, 500);
    glColor3f(1., 1., 1.);
    for (int i = 0; i < pauseMessageSize1; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, gamePauseMessage1[i]);

    glRasterPos2f(700, 450);
    glColor3f(1., 1., 1.);
    for (int i = 0; i < pauseMessageSize2; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, gamePauseMessage2[i]);

    glRasterPos2f(700, 400);
    glColor3f(1., 1., 1.);
    for (int i = 0; i < endMessageSize2; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, gameEndMessage2[i]);
    break;
  }

  glutSwapBuffers();
}

// process "special" keyboard events (those having to do with arrow keys)
void special_keyboard(int key, int x, int y)
{
  if(currentGameMode == PLAY){
    switch (key) {
    case GLUT_KEY_LEFT:
      if(arrows == RIGHT || arrows == LEFT || pressed == true){}
      else {
	arrows = LEFT;
	pressed = true;
      }
      break;
    case GLUT_KEY_RIGHT:
      if(arrows == RIGHT || arrows == LEFT || pressed == true){}
      else {
	arrows = RIGHT;
	pressed = true;
      }
      break;
    case GLUT_KEY_UP:
      if(arrows == UP || arrows == DOWN || pressed == true){}
      else {
	arrows = UP;
	pressed = true;
      }
      break;
    case GLUT_KEY_DOWN:
      if(arrows == UP || arrows == DOWN || pressed == true){}
      else {
	arrows = DOWN;
	pressed = true;
      }
      break;
    }
  }
  glutPostRedisplay();
}

// the reshape function handles the case where the user changes the size
//   of the window.  We need to fix the coordinate
//   system, so that the drawing area is still the unit square.
void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  WIDTH = w;  HEIGHT = h;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0., WIDTH-1, 0., HEIGHT-1, -1.0, 1.0);

}

void idle(){
  glutPostRedisplay();
}

//This is the function that makes the game tick.  Every 500 milliseconds it 
//updates.


void Timer(int a){
  if(currentGameMode == PLAY){
    pressed = false;
    switch(arrows){
    case UP:
      snakeBody.follow();
      head.moveUp(20);
      break;
    case DOWN:
      snakeBody.follow();
      head.moveDown(20);
      break;
    case LEFT:
      snakeBody.follow();
      head.moveLeft(20);
      break;
    case RIGHT:
      snakeBody.follow();
      head.moveRight(20);
      break;
    }
    for (int i=0; i<wall.getLen(); i++)
      if ((wall[i].getX()==head.getX() && wall[i].getY()==head.getY()) || snakeBody.hitBodyCheck() == true)
	currentGameMode = OVER;
    for (int i=0; i<Obs.getLen(); i++)
      if ((Obs[i].getX()==head.getX() && Obs[i].getY()==head.getY()) || snakeBody.hitBodyCheck() == true)
	currentGameMode = OVER;
  }
  glutTimerFunc(speed, Timer, 0);
}

// process keyboard events
void keyboard( unsigned char c, int x, int y ) {
  int win = glutGetWindow();
  switch(c) {
  case 'q':
  case 'Q':
  case 27:
    // get rid of the window (as part of shutting down)
    glutDestroyWindow(win);
    exit(0);
    break;
  case '\b':
    break;
  case 'r':
    if (currentGameMode != PLAY) {
      currentGameMode = PLAY;
      head.setX(760);
      head.setY(500);
      score = 0;
      snakeBody.deleteBody();
      Obs.deleteWallArray();
      wall.setSize(50,40);
      arrows = UP;
    } else {}
    break;
  case 'p':
    if(currentGameMode == PLAY)
      currentGameMode = PAUSE;
    else if(currentGameMode == PAUSE){
      currentGameMode = PLAY;
    }
    break;
  case '1':
    current_color = color1;
    break;
  case '2':
    current_color = color2;
    break;
  case '3':
    current_color = color3;
    break;
  case '4':
    current_color = color4;
    break;
  case '5':
    current_color = color5;
    break;
  case '6':
    current_color = color6;
    break;
  default:
    break;
  }
  glutPostRedisplay();
}

// the init function sets up the graphics card to draw properly
void init(void)
{
  // clear the window to black
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // set up the coordinate system:  number of pixels along x and y
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0., WIDTH-1, 0., HEIGHT-1, -1.0, 1.0);

  // set up how points and lines will be drawn.  The following
  //  commands make points and lines look nice and smooth.
  glPointSize(3);
  glLineWidth(1.5);
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);

  // welcome message
  cout << "Welcome to " << programName << endl;
}

// init_gl_window is the function that starts the ball rolling, in
//  terms of getting everything set up and passing control over to the
//  glut library for event handling.  It needs to tell the glut library
//  about all the essential functions:  what function to call if the
//  window changes shape, what to do to redraw, handle the keyboard,
//  etc.
void init_gl_window()
{
  char *argv[] = {programName};
  int argc = sizeof(argv) / sizeof(argv[0]);
  glutInit(&argc, argv);
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInitWindowPosition(100,100);
  glutCreateWindow(programName);

  backgroundT = loadTexture("background.pam");
  appleT = loadTexture("apple.pam");

  glutTimerFunc(speed, Timer, 0);
  glutIdleFunc(idle);
  init();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(special_keyboard);
  glutMainLoop();
}

int main()
{  
  apple.location(head, snakeBody, Obs);
  init_gl_window(); 
}
