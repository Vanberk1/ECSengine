#pragma once

#include "../Component.h"
#include "../lib/glm/glm.hpp"

class TransformComponent : public Component {
public:
    static constexpr unsigned int ID = 0; // Manual ID. have to automate it 
    
    glm::vec2 position;
};