//
// Created by louan on 18/06/2026.
//

#ifndef MYGAME_GAMESCENE_H
#define MYGAME_GAMESCENE_H
#pragma once

#include "../core/Scene.hpp"
#include "../core/EntityManager.hpp"
#include "../input/KeyboardController.hpp"
#include "Player.hpp"
#include "../config/Settings.hpp"


class GameScene : public Scene {
public:
    explicit GameScene(Settings& settings);

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;

private:
    EntityManager entityManager;
    Settings& settings;

    InputManager input;
    KeyboardController keyboard;
};
#endif //MYGAME_GAMESCENE_H
