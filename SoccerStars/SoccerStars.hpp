#ifndef __FIELDRUNNERS__
#define __FIELDRUNNERS__
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

#include "../main/define.hpp"
#include "../Player/Player.hpp"

using namespace std;

class SoccerStars {
   public:
    SoccerStars();
    void run();
    void run_the_game();
    void get_rounds_number();
    void get_goals_number();
    void read_initial_players_position();
    void initialize_window();
    void set_up_background();
    void release_all_alloc_memory();
    void draw();

   private:
    Window* win;
    std::vector<Player*> blue_players;
    std::vector<Player*> red_players;
    int rounds_number;
    int goals_number;
};

#endif