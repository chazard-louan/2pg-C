//
// Created by louan on 18/06/2026.
//

#pragma once

#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

class Settings {
public:
    // -------- General options --------
    float volume;
    bool fullscreen;
    std::string language;

    // -------- Input --------
    std::string selectedController;

    std::unordered_map<std::string, sf::Keyboard::Key> keybinds;

    // -------- Constructor / Core --------
    Settings();

    void setDefaultKeybinds();

    // -------- Keybind system --------
    void setKeybind(const std::string& action, const sf::Keyboard::Key& key);

    sf::Keyboard::Key getKeybind(const std::string &action) const;
    void resetKeybinds();

    // -------- Controller --------
    void setController(const std::string& controller);

    // -------- Save / Load --------
    void save(const std::string& filename) const;
    void load(const std::string& filename);
};