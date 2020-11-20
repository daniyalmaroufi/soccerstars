#include "Player.hpp"

Player::Player(Point position_, std::string image_dir) : Body(position_, PLAYER_RADIUS) {
    player_image = image_dir;
}

void Player::draw(Window *win) { win->draw_img(player_image, get_box()); }
