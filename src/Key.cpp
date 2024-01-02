
#include "Key.h"

Key::Key(float x, float y, float size_x, float size_y)
    : StaticGameObject(x, y, size_x, size_y) {
  setObjTexture(KEY);
}

Object_ID Key::handleCollision(GameObject& other) {
  return other.handleCollision(*this);
}

Object_ID Key::handleCollision(PacMan& other) {
  gotEaten();
  return Object_ID::AIR;
}