//
// Created by louan on 18/06/2026.
//
#include <SFML/Graphics.hpp>
#include "core/Scene/SceneManager.hpp"
#include "game/GameScene.hpp"
#include "input/KeyboardController.hpp"
#include "config/Settings.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Game");
    window.setFramerateLimit(60);

    Settings settings;
    SceneManager sceneManager(window);
    sceneManager.setScene(std::make_unique<GameScene>(settings));

    sf::Clock clock;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            sceneManager.handleEvent(event);
        }

        float dt = clock.restart().asSeconds();
        dt = std::min(dt, 0.5f);

        sceneManager.update(dt);

        window.clear();
        sceneManager.render();
        window.display();
    }
}