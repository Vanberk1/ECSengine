#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
    std::cout << "Hello world" << std::endl;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL." << std::endl;
        return 0;
    }
    if (TTF_Init() != 0) {
        std::cerr << "Error initializing SDL TTF" << std::endl;
        return 0;
    }

    SDL_Window* window = SDL_CreateWindow(
        "ECSengine 1.0.0v",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        std::cerr << "Error creating SDL window." << std::endl;
        return 0;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Error creating SDL renderer." << std::endl;
        return 0;
    }

    // Game Loop

    bool exitGame = false;
    
    SDL_Event event;
    while(!exitGame) {
        // Event handler
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                exitGame = true;
            }
        }

        // Update

        // Render
        SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }


    return 0;
}