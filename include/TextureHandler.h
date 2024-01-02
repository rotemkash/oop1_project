#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

const int OBJ_NUM = 17;

enum Object_ID {
  CLOCK,
  COOKIE,
  DEMON,
  DEMON_FROZEN,
  DOOR,
  FREEZE,
  HEART,
  KEY,
  DEMON_DRUNK,
  PACMAN_OPEN,
  LEVEL_UP_IMG,
  PACMAN_SUPER_OPEN,
  STAR,
  WALL,
  TIME_UP_IMG,
  GAME_OVER_IMG,
  FINAL_WIN_IMG,
  AIR
};

class TextureHandler {
 public:
  ~TextureHandler();
  static TextureHandler& getInstance();

  sf::Texture* getObjTexture(int objNum);

  sf::Font getFont() const;

 private:
  TextureHandler();
  std::string m_imgNames[OBJ_NUM] = {
      "clock.png",        "cookie.png",   "demon.png",
      "demon_frozen.png", "door.png",     "freeze.png",
      "heart.png",        "key.png",      "drunk_demon.png",
      "pacman_open.png",  "level_up.png", "pacman_super_open.png",
      "star.png",         "wall.png",     "time_up.png",
      "game_over.png",    "final_win.png"};

  sf::Texture m_textures[OBJ_NUM];
  sf::Font m_font;
};