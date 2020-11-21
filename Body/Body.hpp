#ifndef __BODY__
#define __BODY__

#include "../RSDL/rsdl.hpp"
#include "../main/define.hpp"

class Body {
   public:
    Body(position position_, int radius_);
    Body(){};
    Rectangle get_box();
    void move_to_pos(position new_pos);
    position get_position();
    void set_velocity(velocity v_);
    void move_one_frame();
    bool is_moving();

   protected:
    position pos;
    int radius;
    velocity v;
};

#endif