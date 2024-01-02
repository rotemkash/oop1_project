#include "ExtraTimeGift.h"

ExtraTimeGift::ExtraTimeGift(float x, float y, float size_x, float size_y)
    : Gift(x, y, size_x, size_y) {
  setObjTexture(CLOCK);
}

Object_ID ExtraTimeGift::handleCollision(GameObject& other) {
  return other.handleCollision(*this);
}

Object_ID ExtraTimeGift::handleCollision(PacMan& other) {
  gotEaten();
  return Object_ID::AIR;
}