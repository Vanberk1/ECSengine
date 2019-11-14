#pragma once

#include "../System.h"
#include "../Components/TransformComponent.h"
#include "../Components/PhysicsComponent.h"

class PhysicsSystem : public System<TransformComponent, PhysicsComponent> {
    using BaseType = System<TransformComponent, PhysicsComponent>;

public:
    PhysicsSystem(EntityManager* entityManager) : BaseType(entityManager) {}
    void Update(float deltaTime) override;
};