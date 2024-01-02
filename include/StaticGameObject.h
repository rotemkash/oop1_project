#pragma once

#include "GameObject.h"

class StaticGameObject : public GameObject {
 public:
  StaticGameObject(float x, float y, float size_x, float size_y);

  bool isEaten() const;

  void gotEaten();

 private:
  bool m_isEaten = false;
};
