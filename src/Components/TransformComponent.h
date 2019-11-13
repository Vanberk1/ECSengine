#pragma once

#include "../Component.h"
#include "../lib/glm/glm.hpp"

class TransformComponent : public Component {
public:
    glm::vec2 position;
};