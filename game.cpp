#include "game.h"

int direction;
int game_state = BEFORE_START;
int score;
int lives;
bool snake_displayed = false;

void start_game() {
    init_snake();
    init_food();
    score = 0;
    lives = INITIAL_LIVES;
    direction = UP;
    game_state = STARTED;
}

void end_game() {
    game_state = ENDED;
}

void paint_status() {
    // paint the score
    move(0, 5);
    printw("Score %d", score); // string formatting in C++
    move(0, COLS - 10);
    for(int i = 0; i < lives; i++) {
        addstr("O");
    }
    // prompts
    if(game_state == BEFORE_START) {
        move(LINES-1, 5);
        addstr("Press space to start");
    } else if(game_state == STARTED) {

    } else if(game_state == SNAKE_RESET) {
        move(LINES-1, 5);
        addstr("You just lost a life! Press space to continue..");
    } else {
        move(LINES-1, 5);
        addstr("Press space to restart. q to quit");
    }
}

bool execute_frame() {
    paint_border();
    paint_status();
    char key = getch(); // arrows, backspace, del, esc.. are ignored

    if(game_state == BEFORE_START) {
        if(key == 32) {
            start_game();
        }
    } else if(game_state == STARTED) {
        if(key == UP and direction != DOWN) {
            direction = UP;
        } else if(key == DOWN and direction != UP) {
            direction = DOWN;
        } else if(key == LEFT and direction != RIGHT) {
            direction = LEFT;
        } else if(key == RIGHT and direction != LEFT) {
            direction = RIGHT;
        }
        pair<int, int> head = move_snake(direction);
        if(try_comsume_food(head)) {
            grow_snake();
            score++;
        }
        paint_snake();
        paint_food();
        if(has_collision()) {
            lives -= 1;
            reset_snake();
            game_state = SNAKE_RESET;
            if(lives == -1) {
                end_game();
            }
        }
    } else if(game_state == SNAKE_RESET) {
        if(key == 32) {
            game_state = STARTED;
        }
        if(snake_displayed) {
            paint_snake();
        }
        snake_displayed = !snake_displayed;
        paint_food();
    } else {
        paint_snake();
        paint_food();
        if(key == 32) {
            start_game();
        }
        if(key == QUIT) {
            return true;
        }
    }
    return false; // don't exit
}