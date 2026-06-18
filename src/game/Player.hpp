//
// Created by louan on 18/06/2026.
//

#ifndef MYGAME_PLAYERENTITY_H
#define MYGAME_PLAYERENTITY_H
#pragma once

#include "../core/Entity.hpp"
#include "../config/Settings.hpp"
#include "../physics/PhysicsManager.hpp"
#include "../input/Controller.hpp"

class Player : public Entity {
public:
    // Constructor
    Player(Controller &controller, sf::Vector2f initialPosition);

    // Overrides from Entity
    void registerPhysics(PhysicsManager& physics) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;


    float speed = 200.f;
    PhysicsComponent physics;
    sf::RectangleShape shape;
private:
    Controller& controller;

};

#endif //MYGAME_PLAYERENTITY_H
