#include "windowDetails.h"

WINDOW * store_win::win = NULL;
int store_win::win_y = 0;
int store_win::win_x = 0;

store_win::store_win() {
    //not doing anything ":)"
}

void store_win::setwindow(WINDOW * w) {
    win = w;
}

void store_win::sety(int y) {
    win_y = y;
}

void store_win::setx(int x) {
    win_x = x;
}

WINDOW * store_win::getwindow() {
    return win;
}

int store_win::gety() {
    return win_y;
}

int store_win::getx() {
    return win_x;
}
