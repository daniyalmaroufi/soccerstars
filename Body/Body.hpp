#ifndef __BODY__
#define __BODY__

#include "../RSDL/rsdl.hpp"
#include "../main/define.hpp"

class Body {
   public:
    Body(Point position_);
    Body(){};

   protected:
    Point position;
};

#endif