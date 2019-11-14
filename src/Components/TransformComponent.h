#pragma once

#include "../ECSTypes.h"
#include "../Component.h"
#include "../../lib/glm/glm.hpp"
#include <iostream>

class TransformComponent : public Component {
public:
    static constexpr ComponentTypeId ID = 0; // Manual ID. have to automate it 
    
    glm::vec2 position;

    TransformComponent(int x, int y) {
        position.x = x;
        position.y = y;
    }

    void Debug() override {
        std::cout << "ID: " << ID << " x: " << position.x << " y: " << position.y << std::endl;
    }
};