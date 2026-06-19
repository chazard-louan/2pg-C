//
// Created by louan on 19/06/2026.
//

#ifndef MYGAME_PHYSICSCOMPONENT_H
#define MYGAME_PHYSICSCOMPONENT_H

#include <SFML/System/Vector2.hpp>

struct PhysicsComponent {
  sf::Vector2f position{0.f, 0.f};    // State
  sf::Vector2f velocity{0.f, 0.f};    // State

  sf::Vector2f force{0.f, 0.f}; // PhysicsManager inputs
  float mass{1.0f};                   // PhysicsManager inputs
  float damping{2.0f};                // PhysicsManager inputs
  bool useGravity = true;             // PhysicsManager inputs
};

#endif //MYGAME_PHYSICSCOMPONENT_H
