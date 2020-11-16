#include "SoccerStars.hpp"

SoccerStars::SoccerStars() : manager() {}

void SoccerStars::run() {
    manager.initialize_window();
    manager.run();
    return;
}

void SoccerStars::get_rounds_number() {
    cout << "Enter the Number of rounds:";
    cin >> rounds_number;
}
void SoccerStars::get_goals_number() {
    cout << "Enter the Number of goals:";
    cin >> goals_number;
}