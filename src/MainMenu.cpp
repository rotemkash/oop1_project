#include "MainMenu.h"


/* main menu constructor*/
MainMenu::MainMenu() {
    // set the background
  m_mainbg.setPosition(0.f, 0.f);
  m_mainbg.setSize(sf::Vector2f(900.f, 950.f));
  m_mainTx.loadFromFile("main_bg.png");
  m_mainbg.setTexture(&m_mainTx);

  // set the newGame button
  m_newGameBtn.setPosition(250.f, 250.f);
  m_newGameBtn.setSize(sf::Vector2f(400.f, 100.f));
  newBtnTx.loadFromFile("new_game_btn.png");
  m_newGameBtn.setTexture(&newBtnTx);

  // sets the help button
  m_helpBtn.setPosition(250.f, 450.f);
  m_helpBtn.setSize(sf::Vector2f(400.f, 100.f));
  helpBtnTx.loadFromFile("help_btn.png");
  m_helpBtn.setTexture(&helpBtnTx);

  // set the exit button
  m_exitBtn.setPosition(250.f, 650.f);
  m_exitBtn.setSize(sf::Vector2f(400.f, 100.f));
  exitBtnTx.loadFromFile("exit_btn.png");
  m_exitBtn.setTexture(&exitBtnTx);

  // set the help button 
  m_helpPageTx.loadFromFile("instructions.png");
  m_helpTxt.setPosition(0.f, 0.f);
  m_helpTxt.setSize(sf::Vector2f(900.f, 950.f));
  m_helpTxt.setTexture(&m_helpPageTx);
}


// draws the background and buttons on the main menu
void MainMenu::drawMainMenu(sf::RenderWindow* window) {
  window->draw(m_mainbg);
  window->draw(m_newGameBtn);
  window->draw(m_helpBtn);
  window->draw(m_exitBtn);
}

// draws the help page when called
void MainMenu::drawHelpPage(sf::RenderWindow* window) {
  window->draw(m_helpTxt);
}


// returns which button was pressed
int MainMenu::buttonPressed(sf::RenderWindow* window,
                            const sf::Event::MouseButtonEvent& event) {
  if (m_newGameBtn.getGlobalBounds().contains(
          window->mapPixelToCoords({event.x, event.y}))) {
    return NEW_GAME;
  } else if (m_helpBtn.getGlobalBounds().contains(
                 window->mapPixelToCoords({event.x, event.y}))) {
    return HELP;
  } else if (m_exitBtn.getGlobalBounds().contains(
                 window->mapPixelToCoords({event.x, event.y}))) {
    return EXIT;
  }
  return MAIN_MENU;
}
