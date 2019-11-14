#pragma once

#include "Entity.h"
#include "System.h"
#include "Component.h"
#include <vector>

class EntityManager {
private:
    int entitiescount = 0;
    std::vector<std::pair<unsigned int, Entity>> entities;
    std::vector<BaseSystem> systems;
    std::vector<std::vector<Component*>> allComponents;

public:
    EntityManager();
    //~EntityManager();
    void Init();
    void Update(float deltaTime);
    Entity CreateEntity();
    void DeleteEntity(int entityID);
};