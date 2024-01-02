#include "Wall.h"

Wall::Wall(float x, float y, float size_x, float size_y)
    : StaticGameObject(x, y, size_x, size_y) {
  setObjTexture(WALL);
}

Object_ID Wall::handleCollision(GameObject &other) {
  return other.handleCollision(*this);
}

Object_ID Wall::handleCollision(PacMan &other) { return Object_ID::AIR; }
