#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ncurses.h>

#define DEGTORAD(deg) (deg * (180.0f / M_PI))
#define DOT 46

/**
 * poffy / poffx: pupil offsets
 */
void draweye(int y, int x, int poffy, int poffx) {
    int xx, yy;
    float deg;
    int width = 5;
    int height = 5;

    // pupils
    mvprintw(y + poffy, x + poffx, "ø");

    // eyes
    for (deg = 0; deg < 360.0f; deg += 1.0f) {
        xx = (int)(width * cos(DEGTORAD(deg))) + x;
        yy = (int)(height * sin(DEGTORAD(deg))) + y;

        mvaddch(yy, xx, DOT);
    }
}

int main(int argc, char **argv) {
    int ch;
    int row, col, x, y;
    MEVENT event;

    if (!initscr()) {
        exit(1);
    };

    raw();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();

    clear();
    cbreak();

    getmaxyx(stdscr, row, col);

    y = row / 2;
    x = col / 2;
    draweye(y, x - 10, 0, 0);
    draweye(y, x + 10, 0, 0);

    mousemask(ALL_MOUSE_EVENTS, NULL);

    while ((ch = getch()) != 'q') {
        if (ch == KEY_MOUSE) {
            if (getmouse(&event) == OK) {
                if (event.bstate && BUTTON1_PRESSED) {
                    clear();
                    draweye(y, x - 10, -2, -2);
                    draweye(y, x + 10, -2, -2);
                }
            }
        }
        refresh();
    }

    endwin();

    return EXIT_SUCCESS;
}
