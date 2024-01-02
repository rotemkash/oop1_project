#include "SmartDemon.h"

SmartDemon::SmartDemon(float x, float y, float size_x, float size_y,
                       float speed)
    : Demon(x, y, size_x, size_y, speed) {
  setObjTexture(Object_ID::DEMON);
}


/*
* this a simple bfs algorithm for the smart demon to follow the pacman.
* if the pacman is on the left the demon goes to the left until it's parallel to it
* if it's on the right it moves to the left and so on
*/
void SmartDemon::move(sf::Time deltaTime) {
  if (isFrozen()) {
    setObjTexture(Object_ID::DEMON_FROZEN);
    return;
  }

  setObjTexture(Object_ID::DEMON);
  setLastPos(getObjPosition());

  if (10 <= (getPacnmanPosition().x - getObjPosition().x)) {
    directionRight();

  } else if (10 <= (getObjPosition().x - getPacnmanPosition().x)) {
    directionLeft();
  }

  if (10 <= (getPacnmanPosition().y - getObjPosition().y)) {
    directionDown();
  }
  if (10 <= (getObjPosition().y - getPacnmanPosition().y)) {
    directionUp();
  }
  sf::Vector2f newPos =
      sf::Vector2f(getObjPosition() +
                   getObjDirection() * getObjSpeed() * deltaTime.asSeconds());
  setObjPosition(newPos);
}
