//
// Created by louan on 18/06/2026.
//

#include "Settings.hpp"
#include <fstream>
#include <iostream>

// -------- Constructor --------
Settings::Settings()
    : volume(1.0f),
      fullscreen(false),
      language("en"),
      selectedController("keyboard")
{
    setDefaultKeybinds();
}

// -------- Defaults --------
void Settings::setDefaultKeybinds() {
    keybinds = {
        {"move_up", sf::Keyboard::Z},
        {"move_down", sf::Keyboard::S},
        {"move_left", sf::Keyboard::Q},
        {"move_right", sf::Keyboard::D},
        {"jump", sf::Keyboard::Space},
        {"pause", sf::Keyboard::Escape}
    };
}

// -------- Keybinds --------
void Settings::setKeybind(const std::string& action, const sf::Keyboard::Key& key) {
    keybinds[action] = key;
}

sf::Keyboard::Key Settings::getKeybind(const std::string &action) const {
    auto it = keybinds.find(action);
    if (it != keybinds.end())
        return it->second;

    return sf::Keyboard::Unknown;
}

void Settings::resetKeybinds() {
    keybinds.clear();
    setDefaultKeybinds();
}

// -------- Controller --------
void Settings::setController(const std::string& controller) {
    selectedController = controller;
}

// -------- Save --------
void Settings::save(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) return;

    file << volume << "\n";
    file << fullscreen << "\n";
    file << language << "\n";
    file << selectedController << "\n";

    file << keybinds.size() << "\n";

    for (const auto& pair : keybinds) {
        file << pair.first << " "
             << static_cast<int>(pair.second) << "\n";
    }
}

// -------- Load --------
void Settings::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    size_t count;

    file >> volume;
    file >> fullscreen;
    file >> language;
    file >> selectedController;

    file >> count;
    keybinds.clear();

    for (size_t i = 0; i < count; i++) {
        std::string action;
        int keyValue;
        file >> action >> keyValue;
        keybinds[action] = static_cast<sf::Keyboard::Key>(keyValue);
    }
}