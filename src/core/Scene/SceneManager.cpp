//
// Created by louan on 18/06/2026.
//

#include "SceneManager.hpp"

SceneManager::SceneManager(sf::RenderWindow& window)
    : window(window)
{}

void SceneManager::setScene(std::unique_ptr<Scene> newScene) {
    currentScene = std::move(newScene);
}

void SceneManager::handleEvent(sf::Event& event) const {
    if (currentScene)
        currentScene->handleEvent(event);
}

void SceneManager::update(float dt) const {
    if (currentScene)
        currentScene->update(dt);
}

void SceneManager::render() const {
    if (currentScene)
        currentScene->render(window);
}
