

#include "StaticGameObject.h"

StaticGameObject::StaticGameObject(float x, float y, float size_x, float size_y)
    : GameObject(x, y, size_x, size_y) {}

bool StaticGameObject::isEaten() const { return m_isEaten; }

/* set the is eaten flag to true indicating this object was destroyed*/
void StaticGameObject::gotEaten() { m_isEaten = true; }
