//
// Created by louan on 18/06/2026.
//

#ifndef MYGAME_PHYSICMANAGER_H
#define MYGAME_PHYSICMANAGER_H
#pragma once
#include <SFML/Graphics.hpp>


struct PhysicsComponent {
    sf::Vector2f velocity{0.f, 0.f};
    sf::Vector2f acceleration{0.f, 0.f};

    bool useGravity = true;
};

class PhysicsManager {
public:
    void add(PhysicsComponent* phys, sf::RectangleShape* shape);

    void update(float dt) const;

private:
    struct Body {
        PhysicsComponent* physics;
        sf::RectangleShape* shape;
    };

    std::vector<Body> bodies;

    sf::Vector2f gravity{0.f, 980.f};
};

#endif //MYGAME_PHYSICMANAGER_H
