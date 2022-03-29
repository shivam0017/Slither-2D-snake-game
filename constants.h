#ifndef DEF_CONSTANTS

#define DEF_CONSTANTS

// 10 frames per second, 1 frame per 0.1 seconds
// how long does a frame last in microseconds?
// 0.1 seconds = 100,000 microseconds
const int TIME_DELAY_BETWEEN_FRAMES = 100000;

const int UP    = 'w';
const int LEFT  = 'a';
const int DOWN  = 's';
const int RIGHT = 'd';
const int QUIT  = 'q';

// const int UP    = 259;
// const int LEFT  = 258;
// const int DOWN  = 260;
// const int RIGHT = 261;

const int BEFORE_START = 0,
          STARTED = 1,
          ENDED = 2,
          SNAKE_RESET = 3;

const int INITIAL_LIVES = 5;
const int FOOD_COUNT = 5;
#endi