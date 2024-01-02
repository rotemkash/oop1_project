#pragma once

// TODO: deete this, probably
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "TextureHandler.h"

//============-INCLUDES-FOR-COLLISION-===============
class Cookie;
class Demon;
class DrunkDemon;
class SmartDemon;
class Door;
class ExtraLifeGift;
class ExtraTimeGift;
class FreezeGift;
class Gift;
class Key;
class MovingGameObject;
class PacMan;
class StaticGameObject;
class SuperPacmanGift;
class Wall;

class GameObject {
 public:
  GameObject(float x, float y, float size_x, float size_y);

  void render(sf::RenderWindow *target);

  void setObjPosition(sf::Vector2f Newpos);

  void setObjOrigin();
  void faceRight();
  void faceDown();
  void faceLeft();
  void faceUp();

  void setObjTexture(int objNum);

  sf::Vector2f getObjPosition() const;

  sf::FloatRect getObjBound() const;

  sf::Vector2f getObjSize() const;

  virtual ~GameObject() = default;

  //============-COLISIONS-====================

  virtual Object_ID handleCollision(GameObject &) { return Object_ID ::AIR; }

  virtual Object_ID handleCollision(PacMan &) { return Object_ID::AIR; }

  virtual Object_ID handleCollision(Demon &) { return Object_ID::AIR; }

  virtual Object_ID handleCollision(Door &) { return Object_ID::AIR; }

  virtual Object_ID handleCollision(Key &) { return Object_ID::AIR; }

  virtual Object_ID handleCollision(Cookie &) { return Object_ID::AIR; }

  virtual Object_ID handleCollision(Wall &) { return Object_ID::AIR; }

  virtual Object_ID handleCollision(SuperPacmanGift &) {
    return Object_ID::AIR;
  }
  virtual Object_ID handleCollision(ExtraTimeGift &) { return Object_ID::AIR; }
  virtual Object_ID handleCollision(ExtraLifeGift &) { return Object_ID::AIR; }
  virtual Object_ID handleCollision(FreezeGift &) { return Object_ID::AIR; }

 private:
  sf::Vector2f m_current_pos;  // x, y
  sf::Texture m_texture;       // image
  sf::RectangleShape m_shape;
};