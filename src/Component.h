#pragma once

#include "Entity.h"

class Component {
private:
    Entity entity;
    size_t poolIndex;

public:
    Component(Entity entity) : entity(entity) {}
    virtual void Init(void* data);
};