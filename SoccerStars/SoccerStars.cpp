#include "SoccerStars.hpp"

SoccerStars::SoccerStars() {
    blue_player_score = 0;
    red_player_score = 0;
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

void SoccerStars::run() {
    initialize_game();
    run_the_game();
}

void SoccerStars::initialize_game() {
    win = new Window(GAME_WIDTH, GAME_HEIGHT, GAME_NAME);
    ball = new Ball(Point(BALL_INITIAL_X, BALL_INITIAL_Y));
}

void SoccerStars::set_up_background() {
    win->draw_img(BACKGROUND_PATH, get_field_box());
    return;
}

Rectangle SoccerStars::get_field_box() {
    Point top_left(0, 0);
    Point bottom_right(GAME_WIDTH, FIELD_HEIGHT);
    return Rectangle(top_left, bottom_right);
}

void SoccerStars::show_scores() {
    win->show_text("Score: " + to_string(blue_player_score),
                   Point(170, FIELD_HEIGHT + 5), WHITE, GAME_FONT, 25);
    win->show_text("Score: " + to_string(red_player_score),
                   Point(570, FIELD_HEIGHT + 5), WHITE, GAME_FONT, 25);
}

void SoccerStars::release_all_alloc_memory() {
    delete win;
    delete ball;
    release_players(blue_players);
    release_players(red_players);
}

void SoccerStars::release_players(vector<Player*> players) {
    for (auto player : players) delete player;
}

void SoccerStars::draw() {
    win->clear();
    set_up_background();
    ball->draw(win);
    draw_players();
    show_scores();
    win->update_screen();
}

void SoccerStars::draw_players() {
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