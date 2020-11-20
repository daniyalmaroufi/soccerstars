#include "Player.hpp"

Player::Player(Point position_, std::string image_dir)
    : Body(position_, PLAYER_RADIUS) {
    player_image = image_dir;
}

void Player::draw(Window *win) { win->draw_img(player_image, get_box()); }

bool Player::is_in_pos(Point pos) {
    if (pos.x > (position.x - radius) && pos.x < (position.x + radius))
        if (pos.y > (position.y - radius) && pos.y < (position.y + radius))
            return true;
    return false;
}
