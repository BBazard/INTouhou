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
  createBullet();

  while (mWindow.isOpen()) {
    mKeyController.run(*this);
    mBulletMove.run(*this);
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

  mEvent.push_back(Event());
  mLife.push_back(Life(5));
  // @todo change 200 with display
  mPosition.push_back(Position(WINDOW_WIDTH / 2 - 40, 5 * WINDOW_HEIGHT / 6));
  Sprite playerSprite("../sprite/vaisseau.png");
  mSprite.push_back(playerSprite);
  TargetType target = NOTARGET;
  mTarget.push_back(target);
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
  mBitset[DYNAMICS].back() = true;
  // mBitset[EVENT].back() = true;
  mBitset[HITBOX].back() = true;
  // mBitset[LIFE].back() = true;
  mBitset[POSITION].back() = true;
  // mBitset[SHOOT].back() = true;
  mBitset[SPRITE].back() = true;
  mBitset[TARGET].back() = true;

  mEvent.push_back(Event());
  mLife.push_back(Life(5));
  // @todo change position relative to player
  mPosition.push_back(Position(WINDOW_WIDTH / 2 - 40, 5 * WINDOW_HEIGHT / 6));
  Sprite playerSprite("../sprite/bulletPlayer.png");
  mSprite.push_back(playerSprite);
  TargetType target = ENEMY;
  mTarget.push_back(target);
}

void World::createEntity() {
  for (int i = 0; i < COMPONENTNUMBER; ++i)
    mBitset[i].push_back(false);
}


std::vector<bool>& World::getBitset(ComponentType type) {
  return mBitset[type];
}

Sprite& World::getSprites(int ind) {
  return mSprite[ind];
}

Position& World::getPositions(int ind) {
  return mPosition[ind];
}

Event& World::getEvent(int ind) {
  return mEvent[ind];
}
