#pragma once

#include <algorithm>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Cookie.h"
#include "Demon.h"
#include "Door.h"
#include "DrunkDemon.h"
#include "ExtraLifeGift.h"
#include "ExtraTimeGift.h"
#include "FreezeGift.h"
#include "Key.h"
#include "PacMan.h"
#include "SmartDemon.h"
#include "SoundHandler.h"
#include "StatusBar.h"
#include "SuperPacmanGift.h"
#include "Wall.h"

const int GIFT_PTS = 5;
const int KEY_PTS = 7;
const int COOKIE_PTS = 2;
const int TIME_BONUS = 10;
const int FREEZE_TIME = 10;
const int SUPER_TIME = 10;
const int TOP_OFFSET = 50;
const double OBJ_PERCENT = 0.7;
const float PAC_SPEED = 150.f;
const float DEMON_SPEED = 100.f;

class Board {
 public:
  Board();

  void renderObjects(sf::RenderWindow *target);

  void updateObjects();

  int getCookieCout() const;

  int getLevelCount() const;

  int getCurrentLevel() const;

  int getPacmanLive() const;

  int remainningTime() const;

  void resetLevelScore();

  bool loadNextLevel(int levelNum);

  void resetTimers();

 private:
  std::ifstream m_boardFile;

  std::vector<std::unique_ptr<MovingGameObject>> m_MovingObjects;
  std::vector<std::unique_ptr<StaticGameObject>> m_staticObjects;

  int m_rows = 0, m_cols = 0, m_timeLimit = 0;
  int m_cookieCount = 0;
  int m_currentLevel = 0;
  int m_lives = 0, m_score = 0, m_levlInitScore = 0;
  bool m_isSuper = false, m_isFrozen = false;

  sf::Clock m_clock, m_movementClock;
  sf::Time m_SuperTimeStart, m_superCurrTime;
  sf::Time m_freezeTimeStart, m_freezeCurrTime;
  StatusBar m_statusBar;

  void resetVals(int levelNum);
};
