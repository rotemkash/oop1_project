#pragma once

#include "Gift.h"

class ExtraTimeGift : public Gift {
 public:
  ExtraTimeGift(float x, float y, float size_x, float size_y);

  //============-COLISIONS-====================

  virtual Object_ID handleCollision(GameObject &) override;

  virtual Object_ID handleCollision(PacMan &) override;
};
