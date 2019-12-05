#pragma once

#include "ECSTypes.h"
#include <unordered_map>
#include <memory>

class IComponentArray {
public:
    virtual ~IComponentArray() = default;
    virtual void EntityDestroyed(Entity entity) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray {
private:
    std::array<T, MAX_ENTITIES> componentArray;
    std::unordered_map<Entity, unsigned int> entityToIndexMap;
    std::unordered_map<unsigned int, Entity> indexToEntityMap;
    unsigned int size;

public:
    void InsertData(Entity entity, T component) {
        unsigned int newIndex = size;
        entityToIndexMap[entity] = newIndex;
        indexToEntityMap[newIndex] = entity;
        componentArray[newIndex] = component;
        ++size;
    };

    void RemoveData(Entity entity) {
        unsigned int indexOfRemovedEntity = entityToIndexMap[entity];
        unsigned int indexOfLastElement = size - 1;
        componentArray[indexOfRemovedEntity] = componentArray[indexOfLastElement];

        Entity entityOfLastElement = indexToEntityMap[indexOfLastElement];
        entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
        indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

        --size;
    };

    T& GetData(Entity entity) {
        return componentArray[entityToIndexMap[entity]];
    };

    void EntityDestroyed(Entity entity) override {
        if(entityToIndexMap.find(entity) != entityToIndexMap.end())
            RemoveData(entity);
    };
};