#include "MovingGameObject.h"

sf::Vector2f MovingGameObject::m_pacmanPosition = sf::Vector2f(450.f, 450.f);

bool MovingGameObject::m_freeze = false;

MovingGameObject::MovingGameObject(float x, float y, float size_x, float size_y,
                                   float speed)
    : GameObject(x, y, size_x, size_y),
      m_initPosition(sf::Vector2f(x, y)),
      m_lastPosition(sf::Vector2f(x, y)),
      m_speed(speed) {}

/* returns the initial position of the object at the start of the game*/
sf::Vector2f MovingGameObject::getInitPos() const { return m_initPosition; }

/* returns last position before the last move*/
sf::Vector2f MovingGameObject::getLastPos() const { return m_lastPosition; }

void MovingGameObject::setLastPos(const sf::Vector2f& lastPost) {
  m_lastPosition = sf::Vector2f(lastPost);
}

void MovingGameObject::resetToInitPosition() { setObjPosition(m_initPosition); }

/* updates the pacman position so all the moving objects know where pacman is*/
void MovingGameObject::setPacmanPosition(const sf::Vector2f& pacmanPosition) {
  m_pacmanPosition = pacmanPosition;
}

sf::Vector2f MovingGameObject::getPacnmanPosition() { return m_pacmanPosition; }

/* sets the freeze flag to true so the demons know not to move*/
void MovingGameObject::setFreeze() { m_freeze = true; }

void MovingGameObject::resetFreeze() { m_freeze = false; }

bool MovingGameObject::isFrozen() { return m_freeze; }

float MovingGameObject::getObjSpeed() const { return m_speed; }

sf::Vector2f MovingGameObject::getObjDirection() const { return m_direction; }

//sets the direction of the object
void MovingGameObject::resetDirection() { m_direction = sf::Vector2f(0, 0); }

void MovingGameObject::directionUp() { m_direction = sf::Vector2f(0, -1); }

void MovingGameObject::directionDown() { m_direction = sf::Vector2f(0, 1); }

void MovingGameObject::directionRight() { m_direction = sf::Vector2f(1, 0); }

void MovingGameObject::directionLeft() { m_direction = sf::Vector2f(-1, 0); }