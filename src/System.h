#pragma once

class System {
public:
    virtual bool Init() = 0;
    virtual void Update(float deltaTime) = 0;
};