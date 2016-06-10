#include "world.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

World::World() :
  mWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "INTouhou"),
  mDisplay(mWindow),
  mKeyController(mWindow) {
  mWindow.setKeyRepeatEnabled(false);
  mWindow.setFramerateLimit(60);
  // // entity number 0 is empty
  for (int i = 0; i < COMPONENTNUMBER; ++i)
    mBitset.push_back(std::vector<bool>());
}

void World::createBomb() {
  createEntity();

  // mBitset[ANIMATION].back() = true;
  // mBitset[DYNAMICS].back() = true;
  // mBitset[EVENT].back() = true;
  // mBitset[HITBOX].back() = true;
  // mBitset[LIFE].back() = true;
  mBitset[POSITION].back() = true;
  // mBitset[SHOOT].back() = true;
  mBitset[SPRITE].back() = true;
  // mBitset[TARGET].back() = true;
}

void World::run() {
  createPlayer();

  while (mWindow.isOpen()) {
    mKeyController.run(*this);
    mPlayerMove.run(*this);
    mDisplay.run(*this);
  }
}

void World::createPlayer() {
  createEntity();

  // mBitset[ANIMATION].back() = true;
  // mBitset[DYNAMICS].back() = true;
  mBitset[EVENT].back() = true;
  // mBitset[HITBOX].back() = true;
  mBitset[LIFE].back() = true;
  mBitset[POSITION].back() = true;
  // mBitset[SHOOT].back() = true;
  mBitset[SPRITE].back() = true;
  // mBitset[TARGET].back() = true;
  Sprite playerSprite("../sprite/vaisseau.png");
  mSprite.push_back(playerSprite);
  // @todo change 200 with display
  mPosition.push_back(Position(200, 500));
  mLife.push_back(Life(5));
  mEvent.push_back(Event());
}

void World::createEnemy() {
  createEntity();

  // mBitset[ANIMATION].back() = true;
  // mBitset[DYNAMICS].back() = true;
  // mBitset[EVENT].back() = true;
  // mBitset[HITBOX].back() = true;
  mBitset[LIFE].back() = true;
  mBitset[POSITION].back() = true;
  // mBitset[SHOOT].back() = true;
  mBitset[SPRITE].back() = true;
  // mBitset[TARGET].back() = true;
}

void World::createBullet() {
  createEntity();

  // mBitset[ANIMATION].back() = true;
  // mBitset[DYNAMICS].back() = true;
  // mBitset[EVENT].back() = true;
  // mBitset[HITBOX].back() = true;
  // mBitset[LIFE].back() = true;
  mBitset[POSITION].back() = true;
  // mBitset[SHOOT].back() = true;
  mBitset[SPRITE].back() = true;
  // mBitset[TARGET].back() = true;
}

void World::createEntity() {
  for (int i = 0; i < COMPONENTNUMBER; ++i)
    mBitset[i].push_back(false);
}


std::vector<bool>& World::getBitset(ComponentType type) {
  return mBitset[type];
}

std::vector<Sprite>& World::getSprites() {
   return mSprite;
}

std::vector<Position>& World::getPositions() {
  return mPosition;
}

Event& World::getEvent(int ind) {
  return mEvent[ind];
}
