#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Game.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
    std::cout << "Hello world" << std::endl;

    Game* game = new Game();
    game->Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);

    while(game->IsRunning()) {
        game->InputHandler();
        game->Update();
        game->Render();
    }
    game->Destroy();
    return 0;
}