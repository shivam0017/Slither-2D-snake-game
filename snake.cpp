#include "snake.h"

vector<pair<int, int>> body;
pair<int, int> last_tail_location;

void init_snake() {
    // when the game starts, we want the snake to have a lengt of 3 blocks
    body.clear();
    body.push_back({10, 10});
    body.push_back({10, 11});
    body.push_back({10, 12});
}


void reset_snake() {
    init_snake();
}

bool has_collision() {
    // return true if the snake has had a collision
    pair<int, int> head = body[0];
    int x = head.first;
    int y = head.second;
    if(x == 0 or x == LINES - 1 or y == 0 or y == COLS - 1) {
        // collision with a border
        return true;
    }
    // collision with the snake itself
    for(int i = 1; i < body.size(); i++) {
        if(head == body[i]) {
            // collision with some part of the body
            return true;
        }
    }
    // my snake is safe
    return false;
}

void paint_snake() {
    for(int i = 0; i < body.size(); i++) {
        auto location = body[i];
        move(location.first, location.second);
        addstr("#");
    }
}

pair<int, int> move_snake(int direction) {
    last_tail_location = body.back();
    body.pop_back(); // remove the tail
    pair<int, int> head = body[0];
    pair<int, int> new_head = {head.first, head.second};

    if(direction == LEFT) {
        new_head.second -= 1;
    } else if(direction == RIGHT) {
        new_head.second += 1;
    } else if(direction == DOWN) {
        new_head.first += 1;
    } else if(direction == UP) {
        new_head.first -= 1;
    }

    body.insert(body.begin(), new_head);
    return new_head;
}

void grow_snake() {
    body.push_back(last_tail_location);
}