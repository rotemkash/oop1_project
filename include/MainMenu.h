#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "DrunkDemon.h"
#include "Pacman.h"
#include "SoundHandler.h"

enum GAME_STATE { MAIN_MENU, NEW_GAME, HELP, EXIT };

class MainMenu {
 public:
  MainMenu();

  void drawMainMenu(sf::RenderWindow* window);

  void drawHelpPage(sf::RenderWindow* window);

  int buttonPressed(sf::RenderWindow* window,
                    const sf::Event::MouseButtonEvent& event);

 private:
  sf::Texture newBtnTx, helpBtnTx, exitBtnTx, m_mainTx, m_helpPageTx;
  sf::RectangleShape m_mainbg;
  sf::RectangleShape m_newGameBtn;
  sf::RectangleShape m_helpBtn;
  sf::RectangleShape m_exitBtn;
  sf::RectangleShape m_helpTxt;
};