#pragma once

#include <SDL2/SDL.h>
#include "../../lib/glm/glm.hpp"

struct Sprite {
    SDL_Texture* texture;
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
};