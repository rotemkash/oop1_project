
#include "TextureHandler.h"

TextureHandler::~TextureHandler() {}

TextureHandler& TextureHandler::getInstance() {
  static TextureHandler instance;
  return instance;
}

/* loads the textures into an array of textures*/
TextureHandler::TextureHandler() {
  for (int i = 0; i < OBJ_NUM; i++) {
    m_textures[i].loadFromFile(m_imgNames[i]);
  }

  m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
}

/* returns the appropriate texture according to the nmber received*/
sf::Texture* TextureHandler::getObjTexture(int objNum) {
  return &m_textures[objNum];
}

sf::Font TextureHandler::getFont() const { return m_font; }
