#include "PhysicsSystem.h"

void PhysicsSystem::Update(float deltaTime) {
    for(auto& compTuple : components) {
        TransformComponent* transform = std::get<TransformComponent*>(compTuple);
        PhysicsComponent* physics = std::get<PhysicsComponent*>(compTuple);

        transform->position.x += physics->velocity.x;
        transform->position.y += physics->velocity.y;
    }
}