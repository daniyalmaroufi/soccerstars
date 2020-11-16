#include "GameManager.hpp"

void GameManager::initialize_window(){
    win = new Window(GAME_WIDTH, GAME_HEIGHT, GAME_NAME);
    set_up_background();
    // win->play_music(MAIN_MUSIC_PATH);
    Player dani(30,50,"../Assets/Player1.png");
    dani.draw(win);
    win->update_screen();
}

void GameManager::set_up_background() {
    win->draw_img(BACKGROUND_PATH);
    return;
}

void GameManager::release_all_alloc_memory(){
    delete win;
}

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