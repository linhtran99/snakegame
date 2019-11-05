#ifndef _INIT_
#define _INIT_
#include "Snake.h"
#include "Color.h"

enum gameMode {PLAY, PAUSE, OVER};

gameMode currentGameMode = PAUSE;

int WIDTH = 1920;  // width of the user window
int HEIGHT = 1080;  // height of the user window

bool pressed = false;

bool game_end=false;

unsigned int score = 0;
int speed = 200;

char programName[] = "Snake";

const char colorChoice[] = "Choose your color";
const int colorlen = 18;

const char colornum[] = "123456";

const char gameEndMessage1[] = "Game Over";
const int endMessageSize1 = 10;

const char gameEndMessage2[] = "Press R to restart.";
const int endMessageSize2 = 20;

const char gamePauseMessage1[] = "Game Paused";
const int pauseMessageSize1 = 12;

const char gamePauseMessage2[] = "Press P to unpause";
const int pauseMessageSize2 = 19;

char scoreDisplay[] = "Total score: ";
int scorestr = 14;

direction arrows = UP;

Color current_color(0., 1., 0.), color1(1., 0., 0.), color2(0., 1., 0.), color3(0., 0., 1.), color4(1., 1., 0.), color5(1., 0., 1.), color6(0., 1., 1.);

int backgroundT, appleT;

#endif
