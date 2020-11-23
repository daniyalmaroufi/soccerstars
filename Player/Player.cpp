#include "Player.hpp"

Player::Player(position position_, std::string image_dir)
    : Body(position_, PLAYER_RADIUS, PLAYER_MASS) {
    player_image = image_dir;
}

void Player::draw(Window *win) { win->draw_img(player_image, get_box()); }

bool Player::is_in_pos(Point pos_) {
    if (pos_.x > (pos.x - radius) && pos_.x < (pos.x + radius))
        if (pos_.y > (pos.y - radius) && pos_.y < (pos.y + radius))
            return true;
    return false;
}

void Player::reflect_with_edges() {
    if (pos.x < radius) {
        pos.x = 2 * radius - pos.x;
        v.x = -v.x;
    }
    if (pos.x > GAME_WIDTH - radius) {
        pos.x = 2 * (GAME_WIDTH - radius) - pos.x;
        v.x = -v.x;
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