#include "World.h"

void World::Init() {
    componentManager = std::make_unique<ComponentManager>();
    entityManager = std::make_unique<EntityManager>();
    systemManager = std::make_unique<SystemManager>();
}

void World::Update(float deltaTime) {
    systemManager->Update(deltaTime);
}

Entity World::CreateEntity() {
    return entityManager->CreateEntity();
}

void World::DestroyEntity(Entity entity) {
    entityManager->DestroyEntity(entity);
    componentManager->EntityDestroyed(entity);
    systemManager->EntityDestroyed(entity);
}