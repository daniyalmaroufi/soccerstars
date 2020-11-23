#ifndef __PLAYER__
#define __PLAYER__

#include <string>

#include "../Body/Body.hpp"
#include "../RSDL/rsdl.hpp"
#include "../main/define.hpp"

class Player : public Body {
   public:
    Player(position position_, std::string image_dir);
    Player(){};
    bool is_in_pos(Point pos);
    void reflect_with_edges();

   private:
};

#endif