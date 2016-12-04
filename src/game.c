#include "game.h"
#include "events.h"
#include "player.h"
#include "main.h"
#include "highscore.h"
#include "status-display.h"

void run() {

}




void draw_border() {
  int x, y;
  int row,col;
  getmaxyx(stdscr,row,col);
  // create a border
  attron(A_BOLD | COLOR_PAIR(6));
  for(x = 0; x < row; x++) {
    for(y = 0; y < col; y++) {
      if(x==row-1 || x==0 || y==0 || y==col-1) {
        mvprintw(x, y, "#");
      }
    }
  }
}
