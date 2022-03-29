#include "ui.h"

// ncurses will save whatever you have on the screen
// it will clear the screen
// it will take control over the screen
// when you exit, it will release control
// and it will restore whatever you had earlier

void init_ui() {
    setlocale(LC_ALL, ""); // overrides the default locale of ISO-8859-1
    initscr(); // initialize the ncurses mode
    nodelay(stdscr, TRUE); // make getch non-blocking call.
    // by default, whatever you type gets printed out
    noecho(); // turn off the echo behavior
    curs_set(0); // make my cursor invisible
    keypad(stdscr, TRUE); // enable reading of function, arrow, backspace, del .. keys
}

void tear_down_ui() {
    endwin(); // exit the ncurses mode
}

void paint_border() {
    for(int i = 0; i < COLS; i++) {
        move(0, i); // move to the column i in top row
        addstr("\u2588");
        move(LINES - 1, i);
        addstr("\u2588");
    }
    for(int i = 0; i < LINES; i++) {
        move(i, 0); // move to the first col of this row
        addstr("\u2588");
        move(i, COLS - 1); // move to the first col of this row
        addstr("\u2588");
    }
}