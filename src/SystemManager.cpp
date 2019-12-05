#include "SystemManager.h"

void SystemManager::Update(float deltaTime) {
    for(auto& pair : systems) {
        pair.second->Update(deltaTime);
    }
}