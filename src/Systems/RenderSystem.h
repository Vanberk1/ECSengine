#pragma once

#include <SDL2/SDL.h>
#include "../System.h"
#include "../World.h"
#include "../Components/Transform.h"
#include "../Components/Sprite.h"
#include <iostream>

class RenderSystem : public System {
private:
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
public:

	void Init() override {

    }

	void Update(float deltaTime) override {
		extern World world;
        extern SDL_Renderer* renderer;
		for(auto const& entity : entities) {
			auto& sprite = world.GetComponent<Sprite>(entity);
			auto& transform = world.GetComponent<Transform>(entity);

            std::cout << "Entity: " << entity << std::endl;

            sourceRectangle.x = 0;
            sourceRectangle.y = 0;
            sourceRectangle.w = 32;
            sourceRectangle.h = 32;

            destinationRectangle.x = transform.position.x;
            destinationRectangle.y = transform.position.y;
            destinationRectangle.w = 32;
            destinationRectangle.h = 32;

            SDL_RenderCopyEx(renderer, sprite.texture, &sourceRectangle, &destinationRectangle, 0.0, NULL, SDL_FLIP_NONE);

			// SDL_Rect body;
            // body.x = transform.position.x;
            // body.y = transform.position.y;
            // body.w = 50;
            // body.h = 50;

            // SDL_SetRenderDrawColor(renderer, 245, 245, 245, 255);
            // SDL_RenderDrawRect(renderer, &body);
		}
	}

    void SetRenderer(SDL_Renderer* ren) {
    }
};