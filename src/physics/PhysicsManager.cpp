//
// Created by louan on 18/06/2026.
//

#include "PhysicsManager.hpp"


void PhysicsManager::update(const float dt) const {
    for (auto& b : bodies) {

        if (b.physics->useGravity) {
            b.physics->acceleration += gravity;
        }

        b.physics->velocity += b.physics->acceleration * dt;
        b.shape->move(b.physics->velocity * dt);

        b.physics->acceleration = {0.f, 0.f};
    }
}

void PhysicsManager::add(PhysicsComponent* phys, sf::RectangleShape* shape) {
    bodies.push_back({ phys, shape });
}
