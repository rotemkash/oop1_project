#pragma once

#include "Demon.h"

class DrunkDemon : public Demon {
 public:
  DrunkDemon(float x, float y, float size_x, float size_y, float speed);

  void move(sf::Time deltaTime);

 private:
  int m_direction = DIRECTION(rand() % 4);
};
