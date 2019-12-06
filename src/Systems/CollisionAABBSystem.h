#pragma once

#include "../System.h"
#include "../World.h"
#include "../Components/Transform.h"
#include "../Components/ColliderAABB.h"
#include <iostream>

class CollisionAABBSystem : public System {
public:
	void Init() override {

	}

	void Update(float deltaTime) override {
		extern World world;
        extern SDL_Renderer* renderer;
        for(auto it = entities.begin(); it != entities.end(); ++it) {
            auto& entity1 = *it;
            auto& transform1 = world.GetComponent<Transform>(entity1);
            SDL_Rect collider1 = {transform1.position.x, transform1.position.y, transform1.width * transform1.scale.x, transform1.height * transform1.scale.y};
            for(auto it2 = it; it2 != entities.end(); ++it2) {
                if(it != it2) {
                    auto& entity2 = *it2;
                    auto& transform2 = world.GetComponent<Transform>(entity2);
                    // auto& collider2 = world.GetComponent<ColliderAABB>(entity2);
                    SDL_Rect collider2 = {transform2.position.x, transform2.position.y, transform2.width * transform2.scale.x, transform2.height * transform2.scale.y};

                    if(CheckAABBCollision(collider1, collider2)) {
                        std::cout << "Collision: [" << entity1 << ", " << entity2 << "]" << std::endl;
                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                        SDL_RenderDrawRect(renderer, &collider1);
                        SDL_RenderDrawRect(renderer, &collider2);
                    }
                    // else {
                    //     // std::cout << "No Collision" << std::endl;
                    //     SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                    //     SDL_RenderDrawRect(renderer, &collider1);
                    //     SDL_RenderDrawRect(renderer, &collider2);
                    // }
                }
            }
        }
	}

    bool CheckAABBCollision(SDL_Rect& rectangleA, SDL_Rect& rectangleB) {
        return (
            rectangleA.x + rectangleA.w >= rectangleB.x &&
            rectangleB.x + rectangleB.w >= rectangleA.x &&
            rectangleA.y + rectangleA.h >= rectangleB.y &&
            rectangleB.y + rectangleB.h >= rectangleA.y
        );
    }
};