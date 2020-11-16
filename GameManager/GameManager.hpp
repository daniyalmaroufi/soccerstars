#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__
#include <string>
#include <vector>

#include "../RSDL/rsdl.hpp"
#include "../main/define.hpp"
#include "../Player/Player.hpp"

class GameManager {
   public:
    GameManager(){};
    void run();
    void initialize_window();
    void set_up_background();
    void release_all_alloc_memory();
    void initial_players(std::vector<Point> blue_players_,
                         std::vector<Point> red_players_);

   private:
    Window* win;
    std::vector<Player*> blue_players;
    std::vector<Player*> red_players;
};

#endif