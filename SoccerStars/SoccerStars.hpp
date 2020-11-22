#ifndef __FIELDRUNNERS__
#define __FIELDRUNNERS__
#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../Ball/Ball.hpp"
#include "../Player/Player.hpp"
#include "../main/define.hpp"

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
    Rectangle get_field_box();
    void show_scores();
    void release_all_alloc_memory();
    void release_players(vector<Player*> players);
    void draw();
    void draw_players();
    void handle_events();
    bool any_team_won();
    bool any_team_won_in_round();
    bool check_blue_rounds();
    bool check_red_rounds();
    void quit_game();
    Player* select_player(Point mouse_click_pos);
    Player* find_player_by_pos(vector<Player*> players, Point pos);
    void toggle_turn();
    void throw_selected_player(Point mouse_release_pos);
    velocity calculate_initial_velocity(position from_pos, Point to_pos);
    void move_all_bodies_one_frame();
    bool is_all_bodies_moving();
    void play_one_step();
    void handle_impact_with_edges();
    bool is_body_in_the_field(Body* body);
    bool handle_bodies_impact();

   private:
    Window* win;
    Ball* ball;
    std::vector<Player*> blue_players;
    int blue_goals;
    int blue_rounds;
    std::vector<Player*> red_players;
    int red_goals;
    int red_rounds;
    int rounds_number;
    int goals_number;
    bool quit;
    int turn;
    Player* selected_player;
};

#endif