//
// Created by louan on 18/06/2026.
//

#include "GameScene.hpp"

GameScene::GameScene(Settings& settings)
    : settings(settings),
    input(),
    keyboard(input)
{

    keyboard.bind(Action::MoveLeft, sf::Keyboard::A);
    keyboard.bind(Action::MoveRight, sf::Keyboard::D);
    keyboard.bind(Action::MoveUp, sf::Keyboard::W);
    keyboard.bind(Action::MoveDown, sf::Keyboard::S);
    keyboard.bind(Action::Jump, sf::Keyboard::Space);


    auto player = std::make_unique<Player>(keyboard, sf::Vector2f{100.0f,100.0f});
    entityManager.add(std::move(player));
}

void GameScene::handleEvent(sf::Event& event) {
    input.handleEvent(event);
}

void GameScene::update(float dt) {
    entityManager.update(dt);
}

void GameScene::render(sf::RenderWindow& window) {
    entityManager.render(window);
}