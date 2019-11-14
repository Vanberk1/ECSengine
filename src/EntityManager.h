#pragma once

#include "ECSTypes.h"
#include "Entity.h"
#include "System.h"
#include "Component.h"
#include <vector>
#include <map>

class EntityManager {
private:
    using Entities = std::map<EntityId, Entity>;
    using Systems = std::vector<BaseSystem>;
    using Components = std::map<ComponentTypeId, std::map<EntityId, Component>>;

    int lastEntity = 0;
    Entities entities;
    Systems systems;
    Components allComponents;

public:
    EntityManager();
    //~EntityManager();
    void Init();
    void Update(float deltaTime);
    Entity CreateEntity();
    void DeleteEntity(EntityId entityID);

    Entities GetEntities() const { return entities; }
    Components GetComponents() const { return allComponents; }

    template<typename CompType>
    void AddComponent(EntityId entityId, CompType component) {
        std::cout << "test 3" << std::endl;
        std::cout << allComponents.size() << std::endl;
        std::cout << CompType::ID << std::endl;
        auto componentList = allComponents.find(CompType::ID);
        if(componentList != allComponents.end()) {
            auto componentsMap = allComponents[CompType::ID];
            std::cout << "test 4" << std::endl;
            componentsMap[entityId] = component;
            std::cout << "test 5" << std::endl;
        }
        else {
            std::map<EntityId, Component> newComponentList;
            newComponentList[entityId] = component;
            allComponents[CompType::ID] = newComponentList;
        }
    }
};