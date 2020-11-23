#include "Ball.hpp"

Ball::Ball(position position_) : Body(position_, BALL_RADIUS, BALL_MASS, BALL_IMAGE) {}

void Ball::reflect_with_edges() {
    if (pos.x < radius) {
        if (pos.y > GATE_TOP && pos.y < GATE_BOTTOM) {
            v.x = 0;
            v.y = 0;
            pos.x = -radius;
        } else {
            pos.x = 2 * radius - pos.x;
            v.x = -v.x;
        }
    }
    if (pos.x > GAME_WIDTH - radius) {
        if (pos.y > GATE_TOP && pos.y < GATE_BOTTOM) {
            v.x = 0;
            v.y = 0;
            pos.x = GAME_WIDTH + radius;
        } else {
            pos.x = 2 * (GAME_WIDTH - radius) - pos.x;
            v.x = -v.x;
        }
    }
    if (pos.y < radius) {
        pos.y = 2 * radius - pos.y;
        v.y = -v.y;
    }
    if (pos.y > FIELD_HEIGHT - radius) {
        pos.y = 2 * (FIELD_HEIGHT - radius) - pos.y;
        v.y = -v.y;
    }
}

bool Ball::is_goal() {
    return (pos.y > GATE_TOP && pos.y < GATE_BOTTOM &&
            (pos.x < 0 || pos.x > GAME_WIDTH));
}

int Ball::who_scored() {
    if (is_goal())
        if (pos.x < 0)
            return RED_TEAM;
        else
            return BLUE_TEAM;
    return -1;
}