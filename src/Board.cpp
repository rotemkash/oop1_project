#include "Board.h"

Board::Board() : m_currentLevel(0), m_statusBar(3, 1), m_lives(3), m_score(0) {}

/* renders\draws all the objects on  the window*/
void Board::renderObjects(sf::RenderWindow* target) {
  m_statusBar.setTimer(m_clock.getElapsedTime().asSeconds());

  if (m_timeLimit != -1) {
    m_statusBar.setbackwardTimer(m_timeLimit -
                                 m_clock.getElapsedTime().asSeconds());
  }

  m_statusBar.drawStatusBar(target);

  for (size_t i = 0; i < m_staticObjects.size(); i++) {
    (*m_staticObjects[i]).render(target);
  }

  for (size_t i = 0; i < m_MovingObjects.size(); i++) {
    (*m_MovingObjects[i]).render(target);
  }
}

/* updates the objects.
 * for example it asks all the moving objects to move and also it checks for
 * collisions
 */
void Board::updateObjects() {
  Object_ID movePoints;

  // check the time for the super gift
  if (m_isSuper) {
    m_superCurrTime = m_clock.getElapsedTime();
    if (m_superCurrTime.asSeconds() - m_SuperTimeStart.asSeconds() >=
        SUPER_TIME) {
      m_isSuper = false;

      for (size_t i = 0; i < m_MovingObjects.size(); i++) {
        PacMan* pacman = dynamic_cast<PacMan*>(m_MovingObjects[i].get());
        if (pacman) {
          pacman->resetSuper();
          break;
        }
      }
    }
  }

  if (m_isFrozen) {
    m_freezeCurrTime = m_clock.getElapsedTime();
    if (m_freezeCurrTime.asSeconds() - m_freezeTimeStart.asSeconds() >=
        FREEZE_TIME) {
      m_isFrozen = false;

      SoundHandler::getInstance().playSound(Sound_ID::FREEZE_END);
      m_MovingObjects[0]->resetFreeze();
    }
  }

  // move the moving objects
  const auto deltaTime = m_movementClock.restart();
  for (size_t i = 0; i < m_MovingObjects.size(); i++) {
    (*m_MovingObjects[i]).move(deltaTime);

    // for each object check collision with other objects in the vector
    for (size_t j = 0; j < m_MovingObjects.size(); j++) {
      if ((*m_MovingObjects[i])
              .getObjBound()
              .intersects(m_MovingObjects[j]->getObjBound())) {
        movePoints = m_MovingObjects[i]->handleCollision(*m_MovingObjects[j]);

        if (movePoints == Object_ID::DEMON) {
          SoundHandler::getInstance().playSound(Sound_ID::DEATH);
          --m_lives;
          m_statusBar.setLives(m_lives);
          for (size_t o = 0; o < m_MovingObjects.size(); o++) {
            m_MovingObjects[o]->resetToInitPosition();
          }
        }
      }
    }

    // check collision with the static objects
    for (size_t k = 0; k < m_staticObjects.size(); k++) {
      if ((*m_MovingObjects[i])
              .getObjBound()
              .intersects(m_staticObjects[k]->getObjBound())) {
        movePoints = m_MovingObjects[i]->handleCollision(*m_staticObjects[k]);
        movePoints = m_staticObjects[k]->handleCollision(*m_MovingObjects[i]);

        bool yesh_delet = false;

        switch (movePoints) {
          case CLOCK:
            SoundHandler::getInstance().playSound(Sound_ID::TIME_ATE);
            m_statusBar.setScore(m_score += GIFT_PTS);

            if (m_timeLimit != -1) {
              m_timeLimit += TIME_BONUS;
            }
            break;
          case COOKIE:
            SoundHandler::getInstance().playSound(Sound_ID::COOKIE_ATE);
            --m_cookieCount;
            m_statusBar.setScore(m_score += COOKIE_PTS);
            break;
          case DOOR:
            SoundHandler::getInstance().playSound(Sound_ID::DOOR_BREAK);
            break;
          case FREEZE:
            SoundHandler::getInstance().playSound(Sound_ID::FREEZE_ATE);
            m_statusBar.setScore(m_score += GIFT_PTS);

            m_isFrozen = true;
            m_freezeTimeStart = m_clock.getElapsedTime();
            m_freezeCurrTime = m_freezeTimeStart;
            break;
          case HEART:
            SoundHandler::getInstance().playSound(Sound_ID::LIFE_ATE);
            m_statusBar.setScore(m_score += GIFT_PTS);

            m_statusBar.setLives(++m_lives);
            break;
          case KEY:
            for (size_t j = 0; j < m_staticObjects.size(); j++) {
              const type_info& objType = typeid(*m_staticObjects[j]);

              if (objType == typeid(Door)) {
                m_staticObjects[j]->gotEaten();
                SoundHandler::getInstance().playSound(Sound_ID::OPEN_DOOR);
                yesh_delet = true;
                break;
              }
            }
            if (!yesh_delet) {
              SoundHandler::getInstance().playSound(Sound_ID::KEY_ATE);
            }

            m_statusBar.setScore(m_score += KEY_PTS);
            break;
          case STAR:
            m_statusBar.setScore(m_score += GIFT_PTS);
            SoundHandler::getInstance().playSound(Sound_ID::SUPER_ATE);
            m_isSuper = true;
            m_SuperTimeStart = m_clock.getElapsedTime();
            m_superCurrTime = m_SuperTimeStart;
            break;
          default:
            break;
        }
      }
    }

    auto it = m_staticObjects.begin();
    while (it != m_staticObjects.end()) {
      // If element is even number then delete it
      if ((*it)->isEaten()) {
        // Due to deletion in loop, iterator became
        // invalidated. So reset the iterator to next item.
        it = m_staticObjects.erase(it);
      } else {
        it++;
      }
    }
  }
}

/* return how many cookies there's left*/
int Board::getCookieCout() const { return m_cookieCount; }

/* returns the current lvl number*/
int Board::getCurrentLevel() const { return m_currentLevel; }

/* returns the lives of pacman*/
int Board::getPacmanLive() const { return m_lives; }

/* send 1 if there's no time limit, otherwise it returns the remaining time*/
int Board::remainningTime() const {
  return m_timeLimit == -1 ? 1
                           : m_timeLimit - m_clock.getElapsedTime().asSeconds();
}

/* resets the score to what it was before the time ended*/
void Board::resetLevelScore() { m_score = m_levlInitScore; }

/*
 * receives a number and tries to load the level matching that number.
 * if it was able to open a file with that level number it load all the objects
 * and returns true. if the file was not found it returns false
 */
bool Board::loadNextLevel(int levelNum) {
  m_boardFile.open("Board_" + std::to_string(levelNum) + ".txt");

  if (!m_boardFile) {
    return false;
  }

  m_levlInitScore = m_score;
  m_statusBar.setScore(m_score);
  m_boardFile >> m_rows >> m_cols >> m_timeLimit;

  if (m_timeLimit == -1) {
    m_statusBar.resetBackClock();
  }

  // calcualte the tile size according to the row and column number
  int tileSize = 900 / std::max(m_rows, m_cols);

  /* init all variables for the current level */
  resetVals(levelNum);
  /*m_isSuper = false;
  m_isFrozen = false;
  m_MovingObjects.clear();
  m_staticObjects.clear();
  m_currentLevel = levelNum;
  m_cookieCount = 0;
  m_lives = 3;
  m_statusBar.setLives(m_lives);
  m_statusBar.seteLevel(m_currentLevel);*/

  int randNum;
  char c;
  // loop over the files and push objects to the vectors according to the
  // characters in the file
  for (int i = 0; i < m_rows; i++) {
    c = char(m_boardFile.get());  // swallow \n
    for (int j = 0; j < m_cols; j++) {
      c = char(m_boardFile.get());
      if (c != ' ') {
        switch (c) {
          case 'a':
            m_MovingObjects.push_back(std::make_unique<PacMan>(
                float(j * tileSize), float(i * tileSize + TOP_OFFSET),
                float(tileSize * OBJ_PERCENT), float(tileSize * OBJ_PERCENT),
                PAC_SPEED, m_lives));
            break;
          case '&':
            // random number to decide if the demon is smart or not
            randNum = rand() % 2;
            if (randNum == 0) {
              m_MovingObjects.push_back(std::make_unique<SmartDemon>(
                  float(j * tileSize), float(i * tileSize + TOP_OFFSET),
                  float(tileSize * OBJ_PERCENT), float(tileSize * OBJ_PERCENT),
                  DEMON_SPEED));
            } else {
              m_MovingObjects.push_back(std::make_unique<DrunkDemon>(
                  float(j * tileSize), float(i * tileSize + TOP_OFFSET),
                  float(tileSize * OBJ_PERCENT), float(tileSize * OBJ_PERCENT),
                  DEMON_SPEED));
            }

            break;

          case '#':  // Wall
            m_staticObjects.push_back(std::make_unique<Wall>(
                float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
                tileSize));
            break;
          case 'D':  // Door
            m_staticObjects.push_back(std::make_unique<Door>(
                float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
                tileSize));
            break;
          case '%':  // key
            m_staticObjects.push_back(std::make_unique<Key>(
                float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
                tileSize));
            break;
          case '*':  // cookie
            m_staticObjects.push_back(std::make_unique<Cookie>(
                float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
                tileSize));
            ++m_cookieCount;
            break;

          case '$':  // Super
            m_staticObjects.push_back(std::make_unique<SuperPacmanGift>(
                float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
                tileSize));
            break;
          case '+':  // Time
            m_staticObjects.push_back(std::make_unique<ExtraTimeGift>(
                float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
                tileSize));
            break;
          case '0':  // Freeze
            m_staticObjects.push_back(std::make_unique<FreezeGift>(
                float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
                tileSize));
            break;
          case '^':  // Life
            m_staticObjects.push_back(std::make_unique<ExtraLifeGift>(
                float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
                tileSize));
            break;
          default:
            break;
        }
      }
    }
  }

  resetTimers();

  m_boardFile.close();
  return true;
}

/*
 * reset the timers for the game and the ability timers
 */
void Board::resetTimers() {
  m_clock.restart();
  m_movementClock.restart();
  m_SuperTimeStart = m_clock.getElapsedTime();
  m_superCurrTime = m_SuperTimeStart;
  m_freezeTimeStart = m_clock.getElapsedTime();
  m_freezeCurrTime = m_freezeTimeStart;
}

/*
 * reset variables that we need at the start of the level
 * like timers and pacman lives, cookie count, the status bar info.
 */
void Board::resetVals(int levelNum) {
  m_isSuper = false;
  m_isFrozen = false;
  m_MovingObjects.clear();
  m_staticObjects.clear();
  m_currentLevel = levelNum;
  m_cookieCount = 0;
  m_lives = 3;
  m_statusBar.setLives(m_lives);
  m_statusBar.seteLevel(m_currentLevel);
}
