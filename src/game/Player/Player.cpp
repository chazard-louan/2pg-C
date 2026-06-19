//
// Created by louan on 18/06/2026.
//

#include "Player.hpp"

#include <iostream>


Player::Player(Controller& controller, const sf::Vector2f initialPosition)
    : controller(controller)
{
    shape.setSize({50.f, 50.f});
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(initialPosition);

    physics = std::make_unique<PhysicsComponent>();

    physics->position = initialPosition;
    physics->velocity = {0.f, 0.f};
    physics->damping = 1.5f;
    physics->mass = 1.f;

    rope = std::make_unique<RopeComponent>();

    rope->active = false;
    rope->length = 0.f;
}

void Player::update(float dt)
{
    sf::Vector2f input(0.f, 0.f);

    if (controller.isActionDown(Action::MoveLeft))
        input.x -= 1.f;

    if (controller.isActionDown(Action::MoveRight))
        input.x += 1.f;

    if (controller.isActionDown(Action::MoveUp))
        input.y -= 1.f;

    if (controller.isActionDown(Action::MoveDown))
        input.y += 1.f;

    physics->force = input * moveForce;
}

void Player::render(sf::RenderWindow& window) {
    window.draw(shape);
}