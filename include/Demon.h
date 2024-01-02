#pragma once

#include "MovingGameObject.h"
#include "PacMan.h"

enum DIRECTION { UP, RIGHT, DOWN, LEFT };

class Demon : public MovingGameObject {
 public:
  Demon(float x, float y, float size_x, float size_y, float speed);

  //============-COLISIONS-====================

  virtual Object_ID handleCollision(GameObject &other) override;

  virtual Object_ID handleCollision(PacMan &) override;

  virtual Object_ID handleCollision(Wall &) override;

  virtual Object_ID handleCollision(Door &) override;
};