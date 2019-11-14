#pragma once

#include "Entity.h"

class Component {
protected:
    Entity* entity;
    size_t poolIndex;

public:
    virtual ~Component() {}
    virtual void Init() {}
    virtual void Debug() {}
};