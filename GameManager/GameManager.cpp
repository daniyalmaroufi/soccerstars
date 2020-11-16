#include "GameManager.hpp"

void GameManager::initialize_window() {
    win = new Window(GAME_WIDTH, GAME_HEIGHT, GAME_NAME);
    set_up_background();
    // win->play_music(MAIN_MUSIC_PATH);
    Player dani(30, 50, "../Assets/Player1.png");
    dani.draw(win);
    win->update_screen();
}

void GameManager::set_up_background() {
    win->draw_img(BACKGROUND_PATH);
    return;
}

void GameManager::release_all_alloc_memory() { delete win; }

void GameManager::run() {
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        SDL_WaitEvent(&event);

        switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
        }
    }
    release_all_alloc_memory();
    SDL_Quit();
}

void GameManager::initial_players(std::vector<Point> blue_players_,
                                  std::vector<Point> red_players_) {
    for (auto blue_player : blue_players_) {
        blue_players.push_back(
            new Player(blue_player.x, blue_player.y, PLAYER1_PATH));
    }
    for (auto red_player : red_players_) {
        blue_players.push_back(
            new Player(red_player.x, red_player.y, PLAYER2_PATH));
    }
    for(auto player: blue_players){
        player->draw(win);
    }
    for(auto player: red_players){
        player->draw(win);
    }
    win->update_screen();
}