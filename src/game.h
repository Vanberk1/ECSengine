#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Game {
private:
    SDL_Window* window;
    SDL_Renderer* renderer1;
    SDL_Event event;
    bool isRunning;
    int ticksLastFrame;
public:
    Game();
    ~Game();
    void Initialize(int width, int height);
    void LoadLevel();
    void InputHandler();
    void Update();
    void Render();
    void Destroy();
    bool IsRunning() const;

};
