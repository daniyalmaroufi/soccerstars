#ifndef __BODY__
#define __BODY__

#include <cmath>

#include "../RSDL/rsdl.hpp"
#include "../main/define.hpp"

class Body {
   public:
    Body(position position_, int radius_, int mass_, std::string image_);
    Body(){};
    Rectangle get_box();
    void draw(Window* win);
    void move_to_pos(position new_pos);
    position get_position();
    int get_radius();
    void set_velocity(velocity v_);
    void move_one_frame();
    bool is_moving();
    bool has_impact_with(Body* body);
    void reflect_by(Body* body);

   protected:
    position pos;
    int radius;
    velocity v;
    int mass;
    std::string image;
};

#endif