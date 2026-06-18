//
// Created by louan on 18/06/2026.
//

#include "EntityManager.hpp"

void EntityManager::add(std::unique_ptr<Entity> entity) {
    entities.push_back(std::move(entity));
}

void EntityManager::update(const float dt) const {
    for (auto& e : entities)
        e->update(dt);
}

void EntityManager::render(sf::RenderWindow& window) const {
    for (auto& e : entities)
        e->render(window);
}

void EntityManager::registerPhysics(class PhysicsManager& physics) const {
    for (auto& e : entities) {
        e->registerPhysics(physics);
    }
}
