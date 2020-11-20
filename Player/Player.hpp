#ifndef __PLAYER__
#define __PLAYER__

#include <string>

#include "../Body/Body.hpp"
#include "../RSDL/rsdl.hpp"
#include "../main/define.hpp"

class Player : public Body {
   public:
    Player(Point position_, std::string image_dir);
    Player(){};
    void draw(Window *win);
    void update(Window *win);

   private:
    std::string player_image;
};

#endif