
#include "SoundHandler.h"

SoundHandler::~SoundHandler() {}

SoundHandler& SoundHandler::getInstance() {
  static SoundHandler instance;
  return instance;
}

/* loadds the sounds into the buffer array*/
SoundHandler::SoundHandler() {
  for (int i = 0; i < SOUND_NUM; i++) {
    m_buffers[i].loadFromFile(m_soundNames[i]);
  }

  /* matches each sound with it's own buffer*/
  for (int i = 0; i < SOUND_NUM; i++) {
    m_sounds[i].setBuffer(m_buffers[i]);
  }
}

/* plays the sound with the given number*/
void SoundHandler::playSound(Sound_ID id) { m_sounds[id].play(); }
