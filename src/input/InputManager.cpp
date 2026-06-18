//
// Created by louan on 18/06/2026.
//


#include "InputManager.hpp"

// ----------------------------
// Handle SFML events
// ----------------------------

void InputManager::handleEvent(const sf::Event& event) {

    // Key pressed → mark as true
    if (event.type == sf::Event::KeyPressed) {
        keys[event.key.code] = true;
    }

    // Key released → mark as false
    else if (event.type == sf::Event::KeyReleased) {
        keys[event.key.code] = false;
    }
}

// ----------------------------
// Check if a key is currently held
// ----------------------------
bool InputManager::isKeyDown(sf::Keyboard::Key key) const {

    auto it = keys.find(key);

    if (it != keys.end()) {
        return it->second;
    }

    return false;
}