#include "SoccerStars.hpp"

SoccerStars::SoccerStars() : manager() {}

void SoccerStars::run() {
    manager.initialize_window();
    manager.initial_players(blue_players, red_players);
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

void SoccerStars::read_initial_players_position() {
    ifstream fin;
    fin.open(PLAYERS_INITIAL_POSITION);
    int x, y;
    for (int i = 0; i < NUMBER_OF_TEAM_PLAYERS; i++) {
        fin >> x >> y;
        blue_players.push_back(Point(x, y));
    }
    for (int i = 0; i < NUMBER_OF_TEAM_PLAYERS; i++) {
        fin >> x >> y;
        red_players.push_back(Point(x, y));
    }

    fin.close();
}