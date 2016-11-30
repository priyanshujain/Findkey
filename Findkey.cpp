#include<ncurses.h>

#define WALL 0
#define PATH 1
//Keys
#define NONE 10
#define RK 12
#define BK 13
#define GK 14
//GATE
#define RG 22
#define BG 23
#define GG 24

class Tile{
public:
    bool visible;
    int type;
    Tile()
    {
        type = 1;
        visible = true;
    }
    void create(int t)
    {
        type = t;
        visible = true;
    }
};

Tile matrix[100][100];
int pi = 0, pj = 0;
int key;

void initialize()
{
    int mat[10][10] = { {1, 1, 0 , 0, 0, 0, 1, 1, 1, RK},
                        {1, 1, 1 , 1, 1, 0, 1, 0, 0, 0},
                        {0, 1, 0 , 0, 1, 0, 1, RG, 1, 0},
                        {0, 1, 0 , 0, 1, 0, 1, 0, 1, 0},
                        {0, 1, 0 , 0, 1, 0, 1, 0, 1, 0},
                        {0, 1, 0 , 0, 1, 0, 1, 0, 1, 0},
                        {0, 1, 0 , 0, 1, 0, 1, 0, 1, 0},
                        {0, 1, 0 , 0, 1, 0, 1, 0, 1, 0},
                        {0, 1, 0 , 0, 0, 0, 1, 0, 1, 0},
                        {0, 1, 1 , 1, 1, 1, 1, 0, 1, 1}};

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
        {
            matrix[i][j].create(mat[i][j]);
        }
}
void draw()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(pi == i && pj == j)
                mvprintw(pi*2,pj*2," *");
            else
            {
                switch(matrix[i][j].type)
                {
                    case WALL:mvprintw(i*2,j*2," #");
                    break;
                    case RK:
                    attron(COLOR_PAIR(1));
                    mvprintw(i*2,j*2," K");
                    attroff(COLOR_PAIR(1));
                    break;
                    case BK:
                    attron(COLOR_PAIR(2));
                    mvprintw(i*2,j*2," K");
                    attroff(COLOR_PAIR(2));
                    break;
                    case GK:
                    attron(COLOR_PAIR(3));
                    mvprintw(i*2,j*2," K");
                    attroff(COLOR_PAIR(3));
                    break;
                    case RG:
                    attron(COLOR_PAIR(1));
                    mvprintw(i*2,j*2," |");
                    attroff(COLOR_PAIR(1));
                    break;
                    case BG:
                    attron(COLOR_PAIR(2));
                    mvprintw(i*2,j*2," |");
                    attroff(COLOR_PAIR(2));
                    break;
                    case GG:
                    attron(COLOR_PAIR(3));
                    mvprintw(i*2,j*2," |");
                    attroff(COLOR_PAIR(3));
                    break;
                    break;
                }
            }
        }
    }
    refresh();
}

void init_curses() {

  initscr();
  // get more control over the input
  cbreak();
  // getch() returns ERR if no input is present and doesn't wait
  //nodelay(stdscr, TRUE);
  // don't echo the inserted keys to the screen
  noecho();
  // also grab keys like F1 etc.
  keypad(stdscr, TRUE);
}

void end_curses() {
  endwin();
}

int update()
{
  int c = getch();
  switch(c)
  {
      case KEY_UP:
          //cout << endl << "Up" << endl;//key up
          if(pi > 0)
          {
            switch(matrix[pi-1][pj].type)
            {
              case PATH:
              mvprintw(pi*2,pj*2,"  ");
                pi--;
                break;
              case RK:
              mvprintw(pi*2,pj*2,"  ");
                pi--;
                key = RK;
                break;
              case BK:
              mvprintw(pi*2,pj*2,"  ");
                pi--;
                key = BK;
                break;
              case GK:
              mvprintw(pi*2,pj*2,"  ");
                pi--;
                key = GK;
                break;
                case RG:
                if(key == RK)
                {
                  mvprintw(pi*2,pj*2,"  ");
                    pi--;
                    matrix[pi][pj].type = PATH;
                    key = NONE;
                }
                break;
                case BG:
                if(key == BK)
                {
                  mvprintw(pi*2,pj*2,"  ");
                    pi--;
                    matrix[pi][pj].type = PATH;
                    key = NONE;
                }
                break;
                case GG:
                if(key == GK)
                {
                  mvprintw(pi*2,pj*2,"  ");
                    pi--;
                    matrix[pi][pj].type = PATH;
                    key = NONE;
                }
                break;
            }
          }
          break;
      case KEY_DOWN:
          //cout << endl << "Down" << endl;   // key down
          if(pi < 9)
          {
            switch(matrix[pi+1][pj].type)
            {
              case PATH:
              mvprintw(pi*2,pj*2,"  ");
                pi++;
                break;
              case RK:
              mvprintw(pi*2,pj*2,"  ");
                pi++;
                key = RK;
                break;
              case BK:
              mvprintw(pi*2,pj*2,"  ");
                pi++;
                key = BK;
                break;
              case GK:
              mvprintw(pi*2,pj*2,"  ");
                pi++;
                key = GK;
                break;
                case RG:
                if(key == RK)
                {
                  mvprintw(pi*2,pj*2,"  ");
                    pi++;
                    matrix[pi][pj].type = PATH;
                    key = NONE;
                }
                break;
                case BG:
                if(key == BK)
                {
                  mvprintw(pi*2,pj*2,"  ");
                    pi++;
                    matrix[pi][pj].type = PATH;
                    key = NONE;
                }
                break;
                case GG:
                if(key == GK)
                {
                  mvprintw(pi*2,pj*2,"  ");
                    pi++;
                    matrix[pi][pj].type = PATH;
                    key = NONE;
                }
                break;
            }
          }
          break;
      case KEY_LEFT:
          //cout << endl << "Left" << endl;  // key left
          if(pj > 0)
          {
            switch(matrix[pi][pj-1].type)
            {
              case PATH:
              mvprintw(pi*2,pj*2,"  ");
                pj--;
                break;
              case RK:
              mvprintw(pi*2,pj*2,"  ");
                pj--;
                key = RK;
                break;
              case BK:
              mvprintw(pi*2,pj*2,"  ");
                pj--;
                key = BK;
                break;
              case GK:
              mvprintw(pi*2,pj*2,"  ");
                pj--;
                key = GK;
                break;
                case RG:
                if(key == RK)
                {
                  mvprintw(pi*2,pj*2,"  ");
                    pj--;
                    matrix[pi][pj].type = PATH;
                    key = NONE;
                }
                break;
                case BG:
                if(key == BK)
                {
                  mvprintw(pi*2,pj*2,"  ");
                    pj--;
                    matrix[pi][pj].type = PATH;
                    key = NONE;
                }
                break;
                case GG:
                if(key == GK)
                {
                  mvprintw(pi*2,pj*2,"  ");
                    pj--;
                    matrix[pi][pj].type = PATH;
                    key = NONE;
                }
                break;
            }
          }
          break;
      case KEY_RIGHT:
          //cout << endl << "Right" << endl;  // key right
          if(pj < 9)
          {
            switch(matrix[pi][pj+1].type)
            {
              case PATH:
              mvprintw(pi*2,pj*2,"  ");
                pj++;
                break;
              case RK:
              mvprintw(pi*2,pj*2,"  ");
                pj++;
                key = RK;
                break;
              case BK:
              mvprintw(pi*2,pj*2,"  ");
                pj++;
                key = BK;
                break;
              case GK:
              mvprintw(pi*2,pj*2,"  ");
                pj++;
                key = GK;
                break;
                case RG:
                if(key == RK)
                {
                  mvprintw(pi*2,pj*2,"  ");
                    pj++;
                    matrix[pi][pj].type = PATH;
                    key = NONE;
                }
                break;
                case BG:
                if(key == BK)
                {
                  mvprintw(pi*2,pj*2,"  ");
                    pj++;
                    matrix[pi][pj].type = PATH;
                    key = NONE;
                }
                break;
                case GG:
                if(key == GK)
                {
                  mvprintw(pi*2,pj*2,"  ");
                    pj++;
                    matrix[pi][pj].type = PATH;
                    key = NONE;
                }
                break;
            }
          }
          break;
      default:return 1;
          break;
  }
  if(matrix[pi][pj].type == RK || matrix[pi][pj].type == BK || matrix[pi][pj].type == GK)
  {
      matrix[pi][pj].type = PATH;
  }
  attron(A_BOLD);
    mvprintw(pi*2,pj*2," *");
    attroff(A_BOLD);
    refresh();
    return 0;
}

int main(){
  init_curses();
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  initialize();
  key = NONE;
  draw();
  int t = 0;
  while(t == 0)
  {
    t = update();
    mvprintw(40,40,"");
    refresh();
  }
  attron(A_BOLD);
  mvprintw(30, 30, "GAME OVER!!!");
  attroff(A_BOLD);
  getch();
  end_curses();
}
