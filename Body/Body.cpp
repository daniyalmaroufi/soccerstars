#include "Body.hpp"

Body::Body(Point position_, int radius_) {
    position = position_;
    radius = radius_;
}

Rectangle Body::get_box() {
    Point top_left(position.x - radius, position.y - radius);
    Point bottom_right(position.x + radius, position.y + radius);
    Rectangle box(top_left, bottom_right);
    return box;
}

void Body::move_to_pos(Point new_pos) { position = new_pos; }