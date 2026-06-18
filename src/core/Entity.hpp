//
// Created by louan on 18/06/2026.
//

#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void registerPhysics(class PhysicsManager& physics) {}

    virtual ~Entity() = default;
};