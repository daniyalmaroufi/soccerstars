#ifndef __BALL__
#define __BALL__

#include "../Body/Body.hpp"
#include "../RSDL/rsdl.hpp"
#include "../main/define.hpp"

class Ball : public Body {
   public:
    Ball(position position_);
    Ball(){};
    void draw(Window *win);
    void update(Window *win);

   private:
};

#endif