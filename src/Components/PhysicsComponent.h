#pragma once

#include "../ECSTypes.h"
#include "../Component.h"
#include "../../lib/glm/glm.hpp"
#include <iostream>

class PhysicsComponent : public Component {
public:
    static constexpr ComponentTypeId ID = 1; // Manual ID. have to automate it 

    glm::vec2 velocity;

    PhysicsComponent(int x, int y) {
        velocity.x = x;
        velocity.y = y;
    }

    void Debug() override {
        std::cout << "ID: " << ID << " x: " << velocity.x << " y: " << velocity.y << std::endl;
    }
};