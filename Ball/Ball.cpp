#include "Ball.hpp"

Ball::Ball(Point position_) : Body(position_,BALL_RADIUS) {}

void Ball::draw(Window *win) { win->draw_img(BALL_IMAGE, get_box()); }


