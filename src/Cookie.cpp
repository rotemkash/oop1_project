#include "Cookie.h"

Cookie::Cookie(float x, float y, float size_x, float size_y)
    : StaticGameObject(x, y, size_x, size_y) {
  setObjTexture(COOKIE);
}

Object_ID Cookie::handleCollision(GameObject& other) {
  return other.handleCollision(*this);
}

Object_ID Cookie::handleCollision(PacMan&) {
  gotEaten();
  return Object_ID::AIR;
}
