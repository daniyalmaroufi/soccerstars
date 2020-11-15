#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__
#include <string>
#include <vector>

#include "../RSDL/rsdl.hpp"
#include "../main/define.hpp"

class GameManager {
   public:
    GameManager();
    void run();
    void set_up_background();

   private:
    Window* window;
    std::string background_path = BACKGROUND_PATH;
};

#endif