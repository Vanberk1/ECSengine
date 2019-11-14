#include "EntityManager.h"
#include <iostream>
#include "Components/TransformComponent.h"
#include "Components/PhysicsComponent.h"

EntityManager::EntityManager() {
    std::cout << "Entity Manager created" << std::endl;
}

void EntityManager::Update(float deltaTime) {

}

Entity EntityManager::CreateEntity() {
    std::cout << "test 1" << std::endl;
    Entity newEntity = {lastEntity++, this};
    entities[newEntity.id] = newEntity;
    return newEntity;
}

void EntityManager::DeleteEntity(EntityId EntityID) {
}

void EntityManager::Init() {
    std::cout << "Entity Manager initialized"<< std::endl;
    Entity e1 = CreateEntity();
    Entity e2 = CreateEntity();
    Entity e3 = CreateEntity();

    PhysicsComponent p1(0, 0);
    TransformComponent t1(10, 5);
    TransformComponent t2(10, 5);

    e1.AddComponent<PhysicsComponent>(p1);
    e1.AddComponent<TransformComponent>(t1);
    e2.AddComponent<TransformComponent>(t2);

    for(auto it = entities.begin(); it != entities.end(); ++it) {
        std::cout << "Entity ID: " << it->first << std::endl;
    }

    std::cout << std::endl;

    for(auto it = allComponents.begin(); it != allComponents.end(); ++it) {
        std::cout << "Component type Id: " << it->first << std::endl;
        
    }
}
