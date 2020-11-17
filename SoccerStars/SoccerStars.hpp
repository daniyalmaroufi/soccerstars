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
#include "../Ball/Ball.hpp"

using namespace std;

class SoccerStars {
   public:
    SoccerStars();
    void run();
    void run_the_game();
    void get_rounds_number();
    void get_goals_number();
    void read_initial_players_position();
    void initialize_game();
    void set_up_background();
    void release_all_alloc_memory();
    void release_players(vector<Player*> players);
    void draw();
    void draw_players();

   private:
    Window* win;
    std::vector<Player*> blue_players;
    std::vector<Player*> red_players;
    Ball* ball;
    int rounds_number;
    int goals_number;
};

#endif