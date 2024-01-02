#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "TextureHandler.h"

class StatusBar {
 public:
  StatusBar(int health, int level);

  void drawStatusBar(sf::RenderWindow *window);

  void setScore(int score);

  void setLives(int lives);

  void setTimer(int seconds);

  void setbackwardTimer(int seconds);

  void seteLevel(int level);

  void resetBackClock();

 private:
  sf::Font m_font;

  sf::RectangleShape m_healthShape;
  sf::Text m_healthTxt;

  sf::RectangleShape m_clockShape, m_backClockShape;

  std::string m_tmpMin, m_tmpSec;
  int m_minutes, m_seconds;

  sf::Text m_clockTxt, m_backClockTxt;

  sf::Text m_levelTxt;

  sf::Text m_scoreTxt;

  void secondToNormalTime(int seconds);
};