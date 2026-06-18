//
// Created by louan on 18/06/2026.
//

#include "Player.hpp"

Player::Player(Controller& controller, const sf::Vector2f initialPosition)
    : controller(controller)
{
    shape.setSize({50.f, 50.f});
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(initialPosition);
}

void Player::update(const float dt) {
    sf::Vector2f move(0.f, 0.f);

    if (controller.isActionDown(Action::MoveLeft))
        move.x -= speed * dt;

    if (controller.isActionDown(Action::MoveRight))
        move.x += speed * dt;

    if (controller.isActionDown(Action::MoveUp))
        move.y -= speed * dt;

    if (controller.isActionDown(Action::MoveDown))
        move.y += speed * dt;

    shape.move(move);
}

void Player::render(sf::RenderWindow& window) {
    window.draw(shape);
}

void Player::registerPhysics(PhysicsManager& physics) {
    physics.add(&this->physics, &this->shape);
}