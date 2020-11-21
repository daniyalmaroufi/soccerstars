#include "Ball.hpp"

Ball::Ball(position position_) : Body(position_, BALL_RADIUS) {}

void Ball::draw(Window *win) { win->draw_img(BALL_IMAGE, get_box()); }

