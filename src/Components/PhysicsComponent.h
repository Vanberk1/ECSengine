#pragma once

#include "../Component.h"
#include "../lib/glm/glm.hpp"

class PhysicsComponent : public Component {
public:
    static constexpr unsigned int ID = 1; // Manual ID. have to automate it 

    glm::vec2 velocity;
};