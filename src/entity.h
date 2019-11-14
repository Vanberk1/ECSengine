#pragma once

#include "ECSTypes.h"
#include <iostream>
#include <string>

class EntityManager;

class Entity {
public:
    EntityId id;   
    EntityManager* entityManager;

    template<typename CompType>
    void AddComponent(CompType component) {
        std::cout << "test 2" << std::endl;
        entityManager->AddComponent(id, component);
    }
};
