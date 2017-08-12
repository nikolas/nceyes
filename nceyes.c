#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <math.h>

#define DEGTORAD(deg) (deg * (180.0f/M_PI))
#define DOT 46

void draweye(int y, int x) {
    int xx, yy;
    float deg;
    int width = 5;
    int height = 5;

    mvaddch(y, x, 'o');
    for (deg = 0; deg < 360.0f; deg += 1.0f) {
        xx = (int)(width * cos(DEGTORAD(deg))) + x;
        yy = (int)(height * sin(DEGTORAD(deg))) + y;

        mvaddch(yy, xx, DOT);
    }
}

int main(int argc, char **argv) {
    char mesg[] = "O_o";
    int row, col;

    initscr();
    getmaxyx(stdscr, row, col);

    int y = row / 2;
    int x = (col - strlen(mesg)) / 2;
    draweye(y, x - 10);
    draweye(y, x + 10);

    refresh();
    getch();
    endwin();

    return 0;
}
