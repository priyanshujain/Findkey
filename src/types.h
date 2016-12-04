
#ifndef _TYPES_H
#define _TYPES_H

#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct game {
  time_t started;
  time_t ended;
  time_t paused;
  int highscore;
  int rows;
  int columns;
} GAME;

#define HIGHSCORE_NAME_LENGTH 15

typedef struct highscore {
  char name[HIGHSCORE_NAME_LENGTH];
  int points;
  long time_sec;
  int highscore;
} HIGHSCORE;

#include "glog.h"

#endif /* _TYPES_H */
