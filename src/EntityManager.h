#pragma once

#include "ECSTypes.h"
#include <queue>
#include <array>

class EntityManager {
private:
    std::queue<Entity> availableEntities;
    std::array<Signature, MAX_ENTITIES> signatures;
    unsigned int livingEntityCount;

public:
    EntityManager() {
        for(Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
            availableEntities.push(entity);
        }
        signatures = {};
        livingEntityCount = 0;
    };

    Entity CreateEntity() {
        Entity id = availableEntities.front();
        availableEntities.pop();
        ++livingEntityCount;

        return id;
    };

    void DestroyEntity(Entity entity) {
        signatures[entity].reset();
        availableEntities.push(entity);
        --livingEntityCount;
    };

    void SetSignatire(Entity entity, Signature signature) {
        signatures[entity] = signature;
    };

    Signature GetSignature(Entity entity) {
		return signatures[entity];
	}
};