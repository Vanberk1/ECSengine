#pragma once

#include "ECSTypes.h"
#include "System.h"
#include <unordered_map>
#include <memory>
#include <iostream>


class SystemManager {
private:
    std::unordered_map<const char*, Signature> signatures{};
    std::unordered_map<const char*, std::shared_ptr<System>> systems{};

public:
    void Update(float deltaTime);

    template<typename T>
    std::shared_ptr<T> RegisterSystem() {
        const char* typeName = typeid(T).name();
        auto system = std::make_shared<T>();
        systems.insert({typeName, system});
        return system;
    };

    template<typename T>
    void SetSignature(Signature signature) {
        const char* typeName = typeid(T).name();
        signatures.insert({typeName, signature});
    };

    void EntityDestroyed(Entity entity) {
        for (auto const& pair : systems) {
			auto const& system = pair.second;
			system->entities.erase(entity);
		}
    };

    void EntitySignatureChanged(Entity entity, Signature entitySignature) {
        for(auto const& pair : systems) {
            auto const& type = pair.first;
            auto const& system = pair.second;
            auto const& systemSignature = signatures[type];

            if((entitySignature & systemSignature) == systemSignature) {
                system->entities.insert(entity);
            }
            else {
                system->entities.erase(entity);
            }
        }
    }
};