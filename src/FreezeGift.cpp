
#include "FreezeGift.h"

FreezeGift::FreezeGift(float x, float y, float size_x, float size_y)
    : Gift(x, y, size_x, size_y) {
  setObjTexture(FREEZE);
}

Object_ID FreezeGift::handleCollision(GameObject& other) {
  return other.handleCollision(*this);
}

Object_ID FreezeGift::handleCollision(PacMan& other) {
  gotEaten();
  return Object_ID::AIR;
}