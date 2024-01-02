
#include "ExtraLifeGift.h"

ExtraLifeGift::ExtraLifeGift(float x, float y, float size_x, float size_y)
    : Gift(x, y, size_x, size_y) {
  setObjTexture(HEART);
}

Object_ID ExtraLifeGift::handleCollision(GameObject& other) {
  return other.handleCollision(*this);
}

Object_ID ExtraLifeGift::handleCollision(PacMan& other) {
  gotEaten();
  return Object_ID::AIR;
}