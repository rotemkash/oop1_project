
#include "Door.h"

Door::Door(float x, float y, float size_x, float size_y)
    : StaticGameObject(x, y, size_x, size_y) {
  setObjTexture(DOOR);
}

Object_ID Door::handleCollision(GameObject &other) {
  return other.handleCollision(*this);
}

Object_ID Door::handleCollision(PacMan &other) {
    // if pacman was in super state break the door
  if (other.isSuper()) {
    gotEaten();
  }
  return Object_ID::AIR;
}
