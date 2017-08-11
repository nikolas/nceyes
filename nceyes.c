#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#include "nceyes.h"

int main(int argc, char **argv) {
    char mesg[] = "O_o";
    int row, col;

    initscr();
    getmaxyx(stdscr,row,col);
    mvprintw(row/2,(col-strlen(mesg)) / 2, "%s", mesg);
    refresh();
    getch();
    endwin();

    return 0;
}
