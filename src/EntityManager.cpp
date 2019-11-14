#include "EntityManager.h"

#include <iostream>

EntityManager::EntityManager() {
    std::cout << "Entity Manager created" << std::
endl;}

void EntityManager::Update(float deltaTime) {

}

Entity EntityManager::CreateEntity() {
    Entity newEntity = {entitiescount++, this};
    entities.push_back(std::pair<unsigned int, Entity>(newEntity.id, newEntity));
    return newEntity;
}

void EntityManager::Init() {
    std::cout << "Entity Manager initialized"<< std::endl;
    Entity e1 = CreateEntity();
    Entity e2 = CreateEntity();
    Entity e3 = CreateEntity();

    for(std::pair<unsigned int, Entity> entity : entities) {
        std::cout << "Entity ID: " << entity.second.id << std::endl;
    }
}