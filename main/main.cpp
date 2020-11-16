#include <iostream>
#include "define.hpp"
#include "../RSDL/rsdl.hpp"
#include "../GameManager/GameManager.hpp"
#include "../SoccerStars/SoccerStars.hpp"

using namespace std;

int main()
{
    SoccerStars game;
    game.get_rounds_number();
    game.get_goals_number();
    game.run();
    return 0;
}