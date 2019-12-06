#pragma once

#include <SDL2/SDL.h>
#include "../System.h"
#include "../World.h"
#include "../Components/Transform.h"
#include "../Components/Physics.h"
#include <string.h>
#include <iostream>

class ControlSystem : public System {
private:
    uint8_t* prevKeyState;
    const uint8_t* currentKeyState;
    int keyLength;

    bool KeyPressed(SDL_Scancode scanCode) {
        return !prevKeyState[scanCode] && currentKeyState[scanCode];
    }

    bool KeyReleased(SDL_Scancode scanCode) {
        return prevKeyState[scanCode] && !currentKeyState[scanCode];
    }

public:
	void Init() override {
        currentKeyState = SDL_GetKeyboardState(&keyLength);
        prevKeyState = new uint8_t[keyLength];
        memcpy(prevKeyState, currentKeyState, keyLength);
	}

	void Update(float deltaTime) override {
		extern World world;
		for(auto const& entity : entities) {
			if(KeyPressed(SDL_SCANCODE_W) || KeyPressed(SDL_SCANCODE_UP)) {
                std::cout << "W pressed" << std::endl;
            }
            if(KeyPressed(SDL_SCANCODE_A) || KeyPressed(SDL_SCANCODE_LEFT)) {
                std::cout << "A pressed" << std::endl;
            }
            if(KeyPressed(SDL_SCANCODE_S) || KeyPressed(SDL_SCANCODE_DOWN)) {
                std::cout << "S pressed" << std::endl;
            }
            if(KeyPressed(SDL_SCANCODE_D) || KeyPressed(SDL_SCANCODE_RIGHT)) {
                std::cout << "D pressed" << std::endl;
            }
            
            if(KeyReleased(SDL_SCANCODE_W) || KeyReleased(SDL_SCANCODE_UP)) {
                std::cout << "W released" << std::endl;
            }
            if(KeyReleased(SDL_SCANCODE_A) || KeyReleased(SDL_SCANCODE_LEFT)) {
                std::cout << "A released" << std::endl;
            }
            if(KeyReleased(SDL_SCANCODE_S) || KeyReleased(SDL_SCANCODE_DOWN)) {
                std::cout << "S released" << std::endl;
            }
            if(KeyReleased(SDL_SCANCODE_D) || KeyReleased(SDL_SCANCODE_RIGHT)) {
                std::cout << "D released" << std::endl;
            }

            memcpy(prevKeyState, currentKeyState, keyLength);
		}
	}
};