#include "Ball.hpp"

Ball::Ball(Point position_) : Body(position_) {}

void Ball::draw(Window *win) { win->draw_img(BALL_IMAGE, get_box()); }

Rectangle Ball::get_box() {
    Point top_left(position.x - BALL_SIZE, position.y - BALL_SIZE);
    Point bottom_right(position.x + BALL_SIZE, position.y + BALL_SIZE);
    Rectangle box(top_left, bottom_right);
    return box;
}
