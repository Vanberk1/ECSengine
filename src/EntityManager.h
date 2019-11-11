#pragma once

#include "Entity.h"
#include "System.h"
#include <vector>

class EntityManager {
private:
    std::vector<Entity*> entities;
    std::vector<System> systems;

public:
    EntityManager();
    ~EntityManager();
    void Update(float deltaTime);
    System CreateSystem();
    Entity CreateEntity();
    void DeleteEntity(int entityID);
};