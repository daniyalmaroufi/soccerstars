#ifndef __FIELDRUNNERS__
#define __FIELDRUNNERS__
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include "../main/define.hpp"
#include "../Player/Player.hpp"
#include "../GameManager/GameManager.hpp"

using namespace std;

class SoccerStars {
   public:
    SoccerStars();
    void run();
    void get_rounds_number();
    void get_goals_number();
    void read_initial_players_position();

   private:
    GameManager manager;
    vector<Point> blue_players;
    vector<Point> red_players;
    int rounds_number;
    int goals_number;
};

#endif