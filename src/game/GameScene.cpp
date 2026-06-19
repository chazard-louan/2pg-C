//
// Created by louan on 18/06/2026.
//

#include "GameScene.hpp"

#include <iostream>

GameScene::GameScene(Settings& settings)
    : settings(settings),
    input(),
    keyboard(input),
    physicsManager(),
    ropeSystem()//,
    //collisionSystem()
{

    keyboard.bind(Action::MoveLeft, sf::Keyboard::A);
    keyboard.bind(Action::MoveRight, sf::Keyboard::D);
    keyboard.bind(Action::MoveUp, sf::Keyboard::W);
    keyboard.bind(Action::MoveDown, sf::Keyboard::S);
    keyboard.bind(Action::Jump, sf::Keyboard::Space);


    auto player = std::make_unique<Player>(keyboard, sf::Vector2f{100.0f,100.0f});
    entityManager.add(std::move(player));
    for (const auto& e : entityManager.getEntities())
    {
        std::cout << "Is there entity in entity manager: "<< std::endl;
        if (e->physics != nullptr) // tells is got the component
        {
            std::cout << "Adding physics: " << e->physics << std::endl;
            physicsManager.add(e->physics.get());
        }
    }
}

void GameScene::handleEvent(sf::Event& event) {
    input.handleEvent(event);
}

void GameScene::update(float dt) {

    physicsManager.update(dt);

    for (auto& e : entityManager.getEntities())
    {
        if ((e->rope != nullptr) && (e->physics != nullptr))// has rope means has physics but to be sure
        {
            ropeSystem.update(*e->physics, *e->rope, dt);
        }
        if (e->physics != nullptr)// has rope means has physics but to be sure
        {
            e->shape.setPosition(e->physics->position);
        }
        //collisionSystem.update(dt);
        e->update(dt);

    }
}

void GameScene::render(sf::RenderWindow& window) {
    for (auto& e : entityManager.getEntities()) {
        e->render(window);
    }
}