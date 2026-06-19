//
// Created by louan on 18/06/2026.
//

#include "PhysicsManager.hpp"

#include <iostream>


void PhysicsManager::update(const float dt) const {
    for (auto& b : bodies)
    {
        auto* phys = b.physics;

        // 1. Compute total acceleration
        sf::Vector2f acceleration{0.f, 0.f};

        if (phys->useGravity)
        {
            acceleration += gravity;
        }

        acceleration += phys->force / phys->mass;

        // IMPORTANT: clear force AFTER using it
        phys->force = {0.f, 0.f};

        // 2. Apply velocity change from acc
        phys->velocity += acceleration * dt;

        // 3. Apply damping (friction / air resistance)
        // Stable exponential damping
        float dampingFactor = 1.f / (1.f + phys->damping * dt);
        phys->velocity *= dampingFactor;

        // 4. Integrate position
        sf::Vector2f displacement = phys->velocity * dt;
        phys->position += displacement;
        //std::cout << phys->position.x << " " << phys->position.y << std::endl;

    }
}

void PhysicsManager::add(PhysicsComponent* phys) {
    bodies.push_back({ phys });
}
