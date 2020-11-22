#include "Body.hpp"

Body::Body(position position_, int radius_, int mass_) {
    pos = position_;
    radius = radius_;
    v.x = 0;
    v.y = 0;
    mass = mass_;
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
    double speed = sqrt(pow(v.x, 2) + pow(v.y, 2));
    std::cout << "vel mag: " << speed << std::endl;
    if (speed > 0) {
        double new_speed = speed - FRICTION_ACC;
        v.x = (new_speed / speed) * v.x;
        v.y = (new_speed / speed) * v.y;
    }

    pos.x = pos.x - v.x * FRAME_DURATION / 1000;
    pos.y = pos.y - v.y * FRAME_DURATION / 1000;

    if (v.x <= 20 && v.x >= -20) {
        v.x = 0;
    }
    if (v.y <= 20 && v.y >= -20) {
        v.y = 0;
    }
}

bool Body::is_moving() {
    if (!v.x && !v.y) return false;
    std::cout << ":" << v.x << "," << v.y << std::endl;
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
        pos.y = 2 * (FIELD_HEIGHT - radius) - pos.y;
        v.y = -v.y;
    }
}

bool Body::has_impact_with(Body* body) {
    if (sqrt(pow(pos.x - body->pos.x, 2) + pow(pos.y - body->pos.y, 2)) >
        radius + body->radius)
        return false;
    return true;
}

void Body::reflect_by(Body* body) {
    if (has_impact_with(body)) {
        body->v.x =
            body->v.x -
            2 * mass / (mass + body->mass) *
                ((body->v.x - v.x) * (body->pos.x - pos.x) +
                 (body->v.y - v.y) * (body->pos.y - pos.y)) /
                (pow(body->pos.x - pos.x, 2) + pow(body->pos.y - pos.y, 2)) *
                (body->pos.x - pos.x);

        body->v.y =
            body->v.y -
            2 * mass / (mass + body->mass) *
                ((body->v.x - v.x) * (body->pos.x - pos.x) +
                 (body->v.y - v.y) * (body->pos.y - pos.y)) /
                (pow(body->pos.x - pos.x, 2) + pow(body->pos.y - pos.y, 2)) *
                (body->pos.y - pos.y);

        v.x = v.x -
              2 * body->mass / (mass + body->mass) *
                  ((v.x - body->v.x) * (pos.x - body->pos.x) +
                   (v.y - body->v.y) * (pos.y - body->pos.y)) /
                  (pow(body->pos.x - pos.x, 2) + pow(body->pos.y - pos.y, 2)) *
                  (pos.x - body->pos.x);

        v.y = v.y -
              2 * body->mass / (mass + body->mass) *
                  ((v.x - body->v.x) * (pos.x - body->pos.x) +
                   (v.y - body->v.y) * (pos.y - body->pos.y)) /
                  (pow(body->pos.x - pos.x, 2) + pow(body->pos.y - pos.y, 2)) *
                  (pos.y - body->pos.y);
    }
}