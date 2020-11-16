
#include "define.hpp"
#include "../RSDL/rsdl.hpp"
#include "../SoccerStars/SoccerStars.hpp"

using namespace std;

int main()
{
    SoccerStars game;
    game.get_rounds_number();
    game.get_goals_number();
    game.read_initial_players_position();
    game.run();
    return 0;
}