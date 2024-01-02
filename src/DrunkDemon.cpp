#include "DrunkDemon.h"

DrunkDemon::DrunkDemon(float x, float y, float size_x, float size_y,
                       float speed)
    : Demon(x, y, size_x, size_y, speed) {
  setObjTexture(Object_ID::DEMON_DRUNK);
}

void DrunkDemon::move(sf::Time deltaTime) {
  if (isFrozen()) {
    setObjTexture(Object_ID::DEMON_FROZEN);
    return;
  }
  setObjTexture(Object_ID::DEMON_DRUNK);
  setLastPos(getObjPosition());

  /*
   * draw a random number (1-30) if it hits 10
   * the demon draws another random drection
   */
  int switchD = rand() % 30;
  if (switchD == 10) {
    m_direction = DIRECTION(rand() % 4);
  }

  switch (m_direction) {
    case DIRECTION::UP:
      directionUp();
      break;
    case DIRECTION::RIGHT:
      directionRight();
      break;
    case DIRECTION::DOWN:
      directionDown();
      break;
    case DIRECTION::LEFT:
      directionLeft();
      break;

    default:
      break;
  }

  sf::Vector2f newPos =
      sf::Vector2f(getObjPosition() +
                   getObjDirection() * getObjSpeed() * deltaTime.asSeconds());
  setObjPosition(newPos);
}
