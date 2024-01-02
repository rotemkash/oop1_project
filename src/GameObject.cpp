#include "GameObject.h"

GameObject::GameObject(float x, float y, float size_x, float size_y) {
  m_current_pos = sf::Vector2f(x, y);
  m_shape.setPosition(x, y);
  m_shape.setSize(sf::Vector2f(size_x, size_y));
}

/* draws the shampe of this object on the window*/
void GameObject::render(sf::RenderWindow* target) { target->draw(m_shape); }

/* sets the obj position to the new position*/
void GameObject::setObjPosition(sf::Vector2f Newpos) {
  m_current_pos = Newpos;
  m_shape.setPosition(m_current_pos);
}

/* sets the origin to the middle */
void GameObject::setObjOrigin() {
  m_shape.setOrigin(m_shape.getSize().x / 2, m_shape.getSize().y / 2);
}

void GameObject::faceRight() { m_shape.setRotation(0.f); }

void GameObject::faceDown() { m_shape.setRotation(90.f); }

void GameObject::faceLeft() { m_shape.setRotation(180.f); }

void GameObject::faceUp() { m_shape.setRotation(270.f); }

void GameObject::setObjTexture(int objNum) {
  m_shape.setTexture(TextureHandler::getInstance().getObjTexture(objNum));
}

sf::Vector2f GameObject::getObjPosition() const { return m_current_pos; }

sf::FloatRect GameObject::getObjBound() const {
  return m_shape.getGlobalBounds();
}

sf::Vector2f GameObject::getObjSize() const { return m_shape.getSize(); }
