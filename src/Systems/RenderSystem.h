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

        SDL_Rect sourceRectangle;
        SDL_Rect destinationRectangle;
		for(auto const& entity : entities) {
			auto& sprite = world.GetComponent<Sprite>(entity);
			auto& transform = world.GetComponent<Transform>(entity);

            //std::cout << "Entity: " << entity << std::endl;

            sourceRectangle.x = 0;
            sourceRectangle.y = 0;
            sourceRectangle.w = transform.width;
            sourceRectangle.h = transform.height;

            destinationRectangle.x = transform.position.x;
            destinationRectangle.y = transform.position.y;
            destinationRectangle.w = transform.width * transform.scale.x;
            destinationRectangle.h = transform.height * transform.scale.y;

            SDL_RenderCopyEx(renderer, sprite.texture, &sourceRectangle, &destinationRectangle, 0.0, NULL, SDL_FLIP_NONE);
		}
	}

    void SetRenderer(SDL_Renderer* ren) {
    }
};