#pragma once

#include "Demon.h"

class SmartDemon : public Demon {
 public:
  SmartDemon(float x, float y, float size_x, float size_y, float speed);
  void move(sf::Time deltaTime);
};
