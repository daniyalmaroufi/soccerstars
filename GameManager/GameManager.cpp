#include "GameManager.hpp"

void GameManager::initialize_window(){
    window = new Window(GAME_WIDTH, GAME_HEIGHT, GAME_NAME);
    set_up_background();
    window->play_music(MAIN_MUSIC_PATH);
    window->update_screen();
}

void GameManager::set_up_background() {
    window->draw_img(BACKGROUND_PATH);
    return;
}

void GameManager::release_all_alloc_memory(){
    delete window;
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