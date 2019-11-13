#pragma once

#include "Entity.h"
#include "System.h"
#include <vector>

class EntityManager {
private:
    std::vector<Entity*> entities;

public:
    EntityManager();
    ~EntityManager();
    void Update(float deltaTime);
    Entity CreateEntity();
    void DeleteEntity(int entityID);
};