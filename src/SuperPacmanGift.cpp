

#include "SuperPacmanGift.h"

SuperPacmanGift::SuperPacmanGift(float x, float y, float size_x, float size_y)
    : Gift(x, y, size_x, size_y) {
  setObjTexture(STAR);
}

Object_ID SuperPacmanGift::handleCollision(GameObject& other) {
  return other.handleCollision(*this);
}

Object_ID SuperPacmanGift::handleCollision(PacMan& other) {
  gotEaten();
  return Object_ID::AIR;
}
