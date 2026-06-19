//
// Created by louan on 18/06/2026.
//

#ifndef MYGAME_PHYSICMANAGER_H
#define MYGAME_PHYSICMANAGER_H

#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsComponent.hpp"

class PhysicsManager {
public:
    void add(PhysicsComponent* phys);

    void update(float dt) const;

private:
    struct Body {
        PhysicsComponent* physics;
    };

    std::vector<Body> bodies;

    sf::Vector2f gravity{0.f, 980.f};
};

#endif //MYGAME_PHYSICMANAGER_H
