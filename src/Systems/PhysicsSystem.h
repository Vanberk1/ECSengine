#pragma once

#include "../System.h"
#include "../World.h"
#include "../Components/Transform.h"
#include "../Components/Physics.h"
#include <iostream>

class PhysicsSystem : public System {
public:
	void Init() override {

	}

	void Update(float deltaTime) override {
		extern World world;
		for(auto const& entity : entities) {
			auto& physics = world.GetComponent<Physics>(entity);
			auto& transform = world.GetComponent<Transform>(entity);

			physics.velocity += physics.acceleration * deltaTime;
			physics.velocity.y += physics.gravity * deltaTime;
			transform.position += physics.velocity * deltaTime;

			//std::cout << "Entity: " << entity << " - Position [X: " << transform.position.x << ", Y: " << transform.position.y << "]" << std::endl;
		}
	}
};