#include "PacMan.h"

//==========-PUBLICS-==============
PacMan::PacMan(float x, float y, float size_x, float size_y, float speed,
               int lives)
    : MovingGameObject(x + size_x / 2, y + size_y / 2, size_x, size_y, speed),
      m_lives(lives) {
  setObjTexture(PACMAN_OPEN);
  setObjOrigin();
}

void PacMan::move(sf::Time deltaTime) {
  setLastPos(getObjPosition());

  //  input
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    if (getObjPosition().y < 50.f) {
      setObjPosition(sf::Vector2f(getObjPosition().x, 950.f - getObjSize().y));
    }
    faceUp();
    directionUp();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    if (getObjPosition().y > 950.f + getObjSize().y) {
      setObjPosition(sf::Vector2f(getObjPosition().x, 50.f));
    }
    faceDown();
    directionDown();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    if (getObjPosition().x > 900) {
      setObjPosition(sf::Vector2f(0.f, getObjPosition().y));
    }
    faceRight();
    directionRight();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    if (getObjPosition().x < -getObjSize().x) {
      setObjPosition(sf::Vector2f(900.f - getObjSize().x, getObjPosition().y));
    }
    faceLeft();
    directionLeft();
  } else if (sf::Event::KeyReleased) {
    resetDirection();
  }

  sf::Vector2f newPos =
      sf::Vector2f(getObjPosition() +
                   getObjDirection() * getObjSpeed() * deltaTime.asSeconds());
  setObjPosition(newPos);
  setPacmanPosition(getObjPosition());
}

bool PacMan::isSuper() const { return m_isSuper; }

void PacMan::resetSuper() {
  setObjTexture(Object_ID::PACMAN_OPEN);
  m_isSuper = false;
}

int PacMan::getLives() const { return m_lives; }


//==========-HANDLE-COLLISIONS-================
Object_ID PacMan::handleCollision(GameObject &other) {
  return other.handleCollision(*this);
}

Object_ID PacMan::handleCollision(Demon &) {
  if (!m_isSuper) {
    resetFreeze();
    return Object_ID::DEMON;
  }
  return Object_ID::AIR;
}

Object_ID PacMan::handleCollision(Door &) {
  if (!m_isSuper) {
    setObjPosition(getLastPos());
    return Object_ID::AIR;
  }
  return Object_ID::DOOR;
}

Object_ID PacMan::handleCollision(Key &) { return Object_ID::KEY; }

Object_ID PacMan::handleCollision(Cookie &) { return Object_ID::COOKIE; }

Object_ID PacMan::handleCollision(Wall &) {
  setObjPosition(getLastPos());
  return Object_ID::AIR;
}

Object_ID PacMan::handleCollision(SuperPacmanGift &) {
  m_isSuper = true;
  setObjTexture(Object_ID::PACMAN_SUPER_OPEN);
  return Object_ID::STAR;
}

Object_ID PacMan::handleCollision(ExtraLifeGift &) { return Object_ID::HEART; }

Object_ID PacMan::handleCollision(ExtraTimeGift &) { return Object_ID::CLOCK; }

Object_ID PacMan::handleCollision(FreezeGift &) {
  setFreeze();
  return Object_ID::FREEZE;
}