#pragma once

#include "../../lib/glm/glm.hpp"

struct Physics {
    glm::vec2 velocity;
    glm::vec2 acceleration;
    float gravity;
};