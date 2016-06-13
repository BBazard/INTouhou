#include "sound.hpp"
#include <iostream>
#include <map>
#include <string>

std::map<std::string, sf::SoundBuffer> Sound::mPoolBuffer;
std::map<std::string, sf::Sound> Sound::mPoolSound;

Sound::Sound() {
  mSound = NULL;
}

Sound::Sound(const std::string &snd) {
  set(snd);
}

void Sound::set(const std::string &snd) {
  doSet(snd);
  mSound = &(mPoolSound[snd]);
}

void Sound::play(const std::string &snd) {
  doSet(snd);
  mPoolSound[snd].play();
}

void Sound::doSet(const std::string &snd) {
  if (mPoolBuffer.insert(std::make_pair(snd, sf::SoundBuffer())).second) {
    if (!mPoolBuffer[snd].loadFromFile(snd))
      std::cout << "erreur" << std::endl;
    mPoolSound.insert(std::make_pair(snd, sf::Sound()));
    mPoolSound[snd].setBuffer(mPoolBuffer[snd]);
  }
}

