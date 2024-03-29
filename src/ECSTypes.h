#pragma once

#include <bitset>

using Entity = unsigned int;
const Entity MAX_ENTITIES = 5000;

using ComponentType = unsigned int;
const ComponentType MAX_COMPONENTS = 32;

using Signature = std::bitset<MAX_COMPONENTS>;