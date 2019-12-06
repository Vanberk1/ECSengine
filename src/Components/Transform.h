#pragma once

#include "../../lib/glm/glm.hpp"

struct Transform {
    glm::vec2 position;
    glm::vec2 rotation;
    glm::vec2 scale;
    int width;
    int height;
};