#include "GameManager.hpp"

GameManager::GameManager() {
    window = new Window(GAME_WIDTH, GAME_HEIGHT, GAME_NAME);
    set_up_background();
    window->update_screen();
}

void GameManager::set_up_background() {
    window->draw_img(background_path);
    return;
}

void GameManager::run() {
    bool quit = false;
    SDL_Event event;
    window->draw_rect(Rectangle(100, 100, 200, 200));
    window->update_screen();
    while (!quit) {
        SDL_WaitEvent(&event);

        switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
        }
    }

    SDL_Quit();
}