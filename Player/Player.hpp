#ifndef __PLAYER__
#define __PLAYER__

#include <string>

#include "../RSDL/rsdl.hpp"
#include "../main/define.hpp"

class Player {
   public:
    Player(int x, int y, std::string image_dir);
    Player(){};
    void draw(Window *win);
    void update(Window *win);
    Rectangle get_box();

   private:
    Point position;
    std::string player_image;
};

#endif