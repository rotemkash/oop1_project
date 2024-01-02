#pragma once

#include "StaticGameObject.h"

class Key : public StaticGameObject {
 public:
  Key(float x, float y, float size_x, float size_y);

  //============-COLISIONS-====================
  virtual Object_ID handleCollision(GameObject& other) override;
  virtual Object_ID handleCollision(PacMan& other) override;
};