#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__
#include <string>
#include <vector>

#include "../RSDL/rsdl.hpp"
#include "../main/define.hpp"

class GameManager {
   public:
    GameManager(){};
    void run();
    void initialize_window();
    void set_up_background();
    void release_all_alloc_memory();

   private:
    Window* window;
};

#endif