#ifndef W_D
#define W_D

#include <ncurses.h>

class store_win {
    static WINDOW * win;
    static int win_y, win_x;
public:
    store_win();
    void setwindow(WINDOW *);
    void sety(int y);
    void setx(int x);
    WINDOW * getwindow();
    int gety();
    int getx();
};


#endif
