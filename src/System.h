#pragma once

#include "ECSTypes.h"
#include <set>

class System {
public:
    std::set<Entity> entities;   

    virtual ~System() {};  
    virtual void Init() {};
    virtual void Update(float deltaTime) {};
};