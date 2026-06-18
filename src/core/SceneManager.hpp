//
// Created by louan on 18/06/2026.
//

#ifndef MYGAME_SCENEMANAGER_H
#define MYGAME_SCENEMANAGER_H
#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"

class SceneManager {
public:
    explicit SceneManager(sf::RenderWindow& window);

    void setScene(std::unique_ptr<Scene> newScene);

    void handleEvent(sf::Event& event) const;
    void update(float dt) const;
    void render() const;

private:
    sf::RenderWindow& window;
    std::unique_ptr<Scene> currentScene;
};
#endif //MYGAME_SCENEMANAGER_H
