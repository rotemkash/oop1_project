#pragma once

#include "PacMan.h"
#include "StaticGameObject.h"

class Door : public StaticGameObject {
 public:
  Door(float x, float y, float size_x, float size_y);

  //============-COLISIONS-====================

  virtual Object_ID handleCollision(GameObject &) override;

  virtual Object_ID handleCollision(PacMan &) override;
};