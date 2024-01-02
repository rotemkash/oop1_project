#pragma once

#include "GameObject.h"

class MovingGameObject : public GameObject {
 public:
  MovingGameObject(float x, float y, float size_x, float size_y, float speed);

  sf::Vector2f getInitPos() const;

  sf::Vector2f getLastPos() const;

  void setLastPos(const sf::Vector2f &lastPost);

  void resetToInitPosition();

  void setPacmanPosition(const sf::Vector2f &pacmanPosition);

  static sf::Vector2f getPacnmanPosition();

  void setFreeze();

  void resetFreeze();

  static bool isFrozen();

  float getObjSpeed() const;

  sf::Vector2f getObjDirection() const;

  virtual void move(sf::Time deltaTime) = 0;

  void resetDirection();

  void directionUp();

  void directionDown();

  void directionRight();

  void directionLeft();

 private:
  // initial position
  sf::Vector2f m_initPosition;
  // position before last move
  sf::Vector2f m_direction = sf::Vector2f(0, 0);
  sf::Vector2f m_lastPosition;
  static sf::Vector2f m_pacmanPosition;
  static bool m_freeze;
  float m_speed;
};
