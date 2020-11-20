#include "Player.hpp"

Player::Player(Point position_, std::string image_dir) : Body(position_) {
    player_image = image_dir;
}

void Player::draw(Window *win) { win->draw_img(player_image, get_box()); }

Rectangle Player::get_box() {
    Point top_left(position.x - PLAYER_RADIUS, position.y - PLAYER_RADIUS);
    Point bottom_right(position.x + PLAYER_RADIUS, position.y + PLAYER_RADIUS);
    Rectangle box(top_left, bottom_right);
    return box;
}
