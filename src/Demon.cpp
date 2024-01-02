
#include "Demon.h"

Demon::Demon(float x, float y, float size_x, float size_y, float speed)
    : MovingGameObject(x, y, size_x, size_y, speed) {
  resetFreeze();
}

Object_ID Demon::handleCollision(GameObject& other) {
  return other.handleCollision(*this);
}

Object_ID Demon::handleCollision(PacMan&) { return Object_ID::AIR; }

Object_ID Demon::handleCollision(Wall&) {
  setObjPosition(getLastPos());
  return Object_ID::AIR;
}

Object_ID Demon::handleCollision(Door&) {
  setObjPosition(getLastPos());
  return Object_ID::AIR;
}
