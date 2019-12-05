#pragma once

#include <SDL2/SDL.h>
#include "../System.h"
#include "../World.h"
#include "../Components/Transform.h"
#include "../Components/Sprite.h"
#include <iostream>

class RenderSystem : public System {
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

			SDL_Rect body;
            body.x = transform.position.x;
            body.y = transform.position.y;
            body.w = 50;
            body.h = 50;

            SDL_SetRenderDrawColor(renderer, 245, 245, 245, 255);
            SDL_RenderFillRect(renderer, &body);
		}
	}

    void SetRenderer(SDL_Renderer* ren) {
    }
};