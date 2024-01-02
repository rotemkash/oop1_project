#pragma once

#include "MovingGameObject.h"

class PacMan : public MovingGameObject {
 public:
  PacMan(float x, float y, float size_x, float size_y, float speed, int lives);

  void move(sf::Time deltaTime) override;

  bool isSuper() const;

  void resetSuper();

  int getLives() const;
  //============-COLISIONS-====================

  virtual Object_ID handleCollision(GameObject &);

  virtual Object_ID handleCollision(Demon &) override;

  virtual Object_ID handleCollision(Door &) override;

  virtual Object_ID handleCollision(Key &) override;

  virtual Object_ID handleCollision(Cookie &) override;

  virtual Object_ID handleCollision(Wall &) override;

  virtual Object_ID handleCollision(SuperPacmanGift &) override;

  virtual Object_ID handleCollision(ExtraLifeGift &) override;

  virtual Object_ID handleCollision(ExtraTimeGift &) override;

  virtual Object_ID handleCollision(FreezeGift &) override;

 private:
  sf::Texture m_pacTexture;
  bool m_isSuper = false;
  int m_lives;
};