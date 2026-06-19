//
// Created by louan on 18/06/2026.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "../../game/Mecanics/RopeComponent.hpp"
#include "../../physics/PhysicsComponent.hpp"
#include <memory>

class Entity {
public:
    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    std::unique_ptr<PhysicsComponent> physics;
    std::unique_ptr<RopeComponent> rope;
    sf::RectangleShape shape;

    virtual ~Entity() = default;
};