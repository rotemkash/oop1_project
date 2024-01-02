
#include "StatusBar.h"

/* constructor for the status bar.*/
StatusBar::StatusBar(int health, int level) {
  m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
  // health icon
  m_healthShape.setTexture(TextureHandler::getInstance().getObjTexture(6));
  m_healthTxt = sf::Text(": " + std::to_string(health), m_font);
  m_healthShape.setPosition(0.f, 0.f);
  m_healthShape.setSize(sf::Vector2f(50.f, 50.f));
  m_healthTxt.setPosition(sf::Vector2f(50.f, 0.f));

  // forward clock icon
  m_clockShape.setTexture(TextureHandler::getInstance().getObjTexture(0));
  m_clockTxt = sf::Text(": 00:00", m_font);
  m_clockShape.setPosition(150.f, 0.f);
  m_clockShape.setSize(sf::Vector2f(50.f, 50.f));
  m_clockTxt.setPosition(sf::Vector2f(200.f, 0.f));

  // backwards clock icon
  m_backClockShape.setTexture(TextureHandler::getInstance().getObjTexture(0));
  resetBackClock();
  m_backClockShape.setPosition(350.f, 0.f);
  m_backClockShape.setSize(sf::Vector2f(50.f, 50.f));

  // lvl number icon
  m_levelTxt = sf::Text("lvl :" + std::to_string(level), m_font);
  m_levelTxt.setPosition(sf::Vector2f(550.f, 0.f));

  // score icon
  m_scoreTxt = sf::Text("Score :" + std::to_string(0), m_font);
  m_scoreTxt.setPosition(sf::Vector2f(700.f, 0.f));
}


/*
* draws the status bar on the window
*/
void StatusBar::drawStatusBar(sf::RenderWindow* window) {
  window->draw(m_healthShape);
  window->draw(m_healthTxt);
  window->draw(m_clockShape);
  window->draw(m_backClockShape);

  window->draw(m_clockTxt);
  window->draw(m_backClockTxt);
  window->draw(m_levelTxt);

  window->draw(m_scoreTxt);
}

void StatusBar::setScore(int score) {
  m_scoreTxt.setString("Score :" + std::to_string(score));
}

void StatusBar::setLives(int lives) {
  m_healthTxt.setString(": " + std::to_string(lives));
}

/*
* receives the number of seconds passed and shoes it on the timer on the status bar
*/
void StatusBar::setTimer(int seconds) {
  secondToNormalTime(seconds);
  m_clockTxt.setString(": " + m_tmpMin + ":" + m_tmpSec);
}

void StatusBar::setbackwardTimer(int seconds) {
  secondToNormalTime(seconds);
  m_backClockTxt.setString(": " + m_tmpMin + ":" + m_tmpSec);
}

void StatusBar::seteLevel(int level) {
  m_levelTxt.setString("lvl :" + std::to_string(level));
}

/*
* converts the seconds to normal xx:xx representation
*/
void StatusBar::secondToNormalTime(int seconds) {
  m_seconds = seconds;
  m_minutes = m_seconds / 60;
  m_seconds = m_seconds - m_minutes * 60;

  m_tmpMin = std::to_string(m_minutes);
  if (m_minutes < 10) {
    m_tmpMin = "0" + std::to_string(m_minutes);
  }

  m_tmpSec = std::to_string(m_seconds);
  if (m_seconds < 10) {
    m_tmpSec = "0" + std::to_string(m_seconds);
  }
}

/* resets the backward clock. we also use this to disable it when there's
* no time limit
*/
void StatusBar::resetBackClock() {
  m_backClockTxt = sf::Text(": --:--", m_font);
  m_backClockTxt.setPosition(sf::Vector2f(400.f, 0.f));
}
