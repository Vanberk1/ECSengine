#pragma once

class EntityManager;

class BaseSystem {
protected:
    EntityManager* entityManager;
public:
    BaseSystem(EntityManager* entityManager) : entityManager(entityManager) {}

    virtual bool Init() = 0;
    virtual void Update(float deltaTime) = 0;
};