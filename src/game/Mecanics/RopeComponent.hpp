//
// Created by louan on 19/06/2026.
//

#ifndef MYGAME_ROPECOMPONENT_H
#define MYGAME_ROPECOMPONENT_H
#pragma once
#include<vector>
#include<SFML/System/Vector2.hpp>
struct RopeComponent
{
  std::vector<sf::Vector2f> anchors;
  float length = 0.f;
  bool active = false;
};
#endif //MYGAME_ROPECOMPONENT_H
