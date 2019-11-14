#pragma once

#include <string>

class EntityManager;

class Entity {
public:
    unsigned int id;   
    EntityManager* entityManager;
};
