#ifndef __BODY__
#define __BODY__

#include "../RSDL/rsdl.hpp"
#include "../main/define.hpp"

class Body {
   public:
    Body(Point position_, int radius_);
    Body(){};
    Rectangle get_box();
    void move_to_pos(Point new_pos);
    Point get_position();

   protected:
    Point position;
    int radius;
    velocity v;
};

#endif