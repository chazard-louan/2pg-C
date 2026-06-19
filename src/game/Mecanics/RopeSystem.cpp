//
// Created by louan on 19/06/2026.
//
#include "RopeSystem.hpp"

#include <cmath>

float length(const sf::Vector2f& v)
{
  return std::sqrt(v.x * v.x + v.y * v.y);
}

void RopeSystem::update(PhysicsComponent& phys, RopeComponent& rope, float dt)
{
  if (!rope.active || rope.anchors.empty())
    return;

  typename sf::Vector2f anchor = rope.anchors.back();

  sf::Vector2f toEntity = phys.position - anchor;
  float dist = length(toEntity);

  if (dist <= rope.length)
    return; // no constraint needed

  sf::Vector2f dir = toEntity / dist;

  // 1. project position back onto circle
  sf::Vector2f correctedPos = anchor + dir * rope.length;

  // 2. recompute velocity to avoid jitter
  phys.velocity = (correctedPos - phys.position) / dt;

  // 3. apply correction
  phys.position = correctedPos;
}
