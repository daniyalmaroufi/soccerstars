#include "SoccerStars.hpp"

SoccerStars::SoccerStars() {}

void SoccerStars::run() {
    initialize_window();
    run_the_game();
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
        blue_players.push_back(new Player(Point(x, y), PLAYER1_PATH));
    }
    for (int i = 0; i < NUMBER_OF_TEAM_PLAYERS; i++) {
        fin >> x >> y;
        red_players.push_back(new Player(Point(x, y), PLAYER2_PATH));
    }

    fin.close();
}

void SoccerStars::initialize_window() {
    win = new Window(GAME_WIDTH, GAME_HEIGHT, GAME_NAME);
}

void SoccerStars::set_up_background() {
    win->draw_img(BACKGROUND_PATH);
    return;
}

void SoccerStars::release_all_alloc_memory() { delete win; }

void SoccerStars::draw() {
    win->clear();
    set_up_background();
    draw_players();
    win->update_screen();
}

void SoccerStars::draw_players(){
    for (auto player : blue_players) player->draw(win);
    for (auto player : red_players) player->draw(win);
}

void SoccerStars::run_the_game() {
    bool quit = false;
    SDL_Event event;
    draw();
    while (!quit) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
        }
        delay(GAME_DELAY);
    }
    release_all_alloc_memory();
    SDL_Quit();

}