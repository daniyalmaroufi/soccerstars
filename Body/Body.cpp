#include "Body.hpp"

Body::Body(position position_, int radius_) {
    pos = position_;
    radius = radius_;
    v.x = 0;
    v.y = 0;
}

Rectangle Body::get_box() {
    Point top_left(pos.x - radius, pos.y - radius);
    Point bottom_right(pos.x + radius, pos.y + radius);
    Rectangle box(top_left, bottom_right);
    return box;
}

void Body::move_to_pos(position new_pos) { pos = new_pos; }

position Body::get_position() { return pos; }

void Body::set_velocity(velocity v_) { v = v_; }

void Body::move_one_frame() {
    double velocity_magnitude = sqrt(pow(v.x, 2) + pow(v.x, 2));
    if (velocity_magnitude > 0) {
        std::cout << "decceleating" << std::endl;
        double new_magnitude = velocity_magnitude - FRICTION_ACC;
        v.x = (new_magnitude / velocity_magnitude) * v.x;
        v.y = (new_magnitude / velocity_magnitude) * v.y;
    }

    pos.x = pos.x - v.x * FRAME_DURATION / 1000;
    pos.y = pos.y - v.y * FRAME_DURATION / 1000;

    if (v.x <= 20 && v.x >= -20) {
        v.x = 0;
        std::cout << "x stoped" << v.x << std::endl;
    }
    if (v.y <= 20 && v.y >= -20) {
        v.y = 0;
        std::cout << "y stoped" << v.y << std::endl;
    }
}

bool Body::is_moving() {
    if (!v.x && !v.y) return false;
    std::cout << "i'm moving:" << v.x << "," << v.y << std::endl;
    return true;
}

int Body::get_radius() { return radius; }

void Body::reflect_with_edges() {
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
        pos.x = 2 * (FIELD_HEIGHT - radius) - pos.y;
        v.y = -v.y;
    }
}