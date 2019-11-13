#pragma once

#include "../Component.h"
#include "../lib/glm/glm.hpp"

class PhysicsComponent : public Component {
public:
    glm::vec2 velocity;

    PhysicsComponent(int velX, int velY) {
        velocity.x = velX;
        velocity.y = velY;
    }
};