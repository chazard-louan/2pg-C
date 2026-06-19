//
// Created by louan on 18/06/2026.
//

#ifndef MYGAME_GAMESCENE_H
#define MYGAME_GAMESCENE_H
#pragma once

#include "../core/Scene/Scene.hpp"
#include "../core/Entity/EntityManager.hpp"
#include "../input/KeyboardController.hpp"
#include "Player/Player.hpp"
#include "../config/Settings.hpp"
#include "../physics/PhysicsManager.hpp"
#include "Mecanics/RopeSystem.hpp"

class GameScene : public Scene {
public:
    explicit GameScene(Settings& settings);

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;

private:
    EntityManager entityManager;
    Settings& settings;
    PhysicsManager physicsManager;
    InputManager input;
    KeyboardController keyboard;
    RopeSystem ropeSystem;
    //CollisionSystem collisionSystem;
};
#endif //MYGAME_GAMESCENE_H
