#include "Player.hpp"

Player::Player(position position_, std::string image_dir)
    : Body(position_, PLAYER_RADIUS) {
    player_image = image_dir;
}

void Player::draw(Window *win) { win->draw_img(player_image, get_box()); }

bool Player::is_in_pos(Point pos_) {
    if (pos_.x > (pos.x - radius) && pos_.x < (pos.x + radius))
        if (pos_.y > (pos.y - radius) && pos_.y < (pos.y + radius))
            return true;
    return false;
}
