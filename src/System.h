#pragma once

#include "BaseSystem.h"
#include <vector>
#include <tuple>

template<class... Comps>
class System : public BaseSystem {
protected:
    std::vector<std::tuple<Comps...>> components;
};