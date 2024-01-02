#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

const int SOUND_NUM = 16;

enum Sound_ID {
  COOKIE_ATE,
  DEATH,
  DOOR_BREAK,
  FREEZE_ATE,
  GAME_OVER_SND,
  GAME_START,
  FREEZE_END,
  KEY_ATE,
  LIFE_ATE,
  OPEN_DOOR,
  SELECTED,
  SUPER_ATE,
  TIME_ATE,
  WON_LEVEL_SND,
  FINAL_WIN_SND,
  TIME_UP_SND
};

class SoundHandler {
 public:
  ~SoundHandler();
  static SoundHandler& getInstance();

  void playSound(Sound_ID id);

 private:
  SoundHandler();

  std::string m_soundNames[SOUND_NUM] = {
      "cookie_ate.wav", "death.wav",      "door_break.wav", "freeze_ate.wav",
      "game_over.wav",  "game_start.wav", "freeze_end.wav", "key_ate.wav",
      "life_ate.wav",   "open_door.wav",  "selected.wav",   "super_ate.wav",
      "time_ate.wav",   "won_level.wav",  "final_win.wav",  "time_up.wav"};

  sf::SoundBuffer m_buffers[SOUND_NUM];
  sf::Sound m_sound;
  sf::Sound m_sounds[SOUND_NUM];
};
