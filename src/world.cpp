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
  mEntityType.push_back(BOMB);
}

void World::run() {
  createPlayer();
  createEnemy();
  int X = World::getPosition(0).x() + World::getSprite(0).getSizeX()/2;
  int Y = World::getPosition(0).y() + World::getSprite(0).getSizeY()/2;
  Position m(X, Y);
  createBullet(m);

  mClock.restart();

  while (mWindow.isOpen()) {
    mKeyController.run(*this);
    mCreatePlayerBullet.run(*this);
    mBulletMove.run(*this);
    mEnemyMove.run(*this);
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

  mDynamics.push_back(Dynamics());
  mEvent.push_back(Event());
  mLife.push_back(Life(5));
  // @todo change 200 with display
  mPosition.push_back(Position(WINDOW_WIDTH/2 - 40, 5*WINDOW_HEIGHT/6));
  Sprite playerSprite("../sprite/vaisseau.png");
  mSprite.push_back(playerSprite);
  TargetType target = NOTARGET;
  mTarget.push_back(target);
  mEntityType.push_back(PLAYERSHIP);
}

void World::createEnemy() {
  createEntity();

  // mBitset[ANIMATION].back() = true;
  // mBitset[DYNAMICS].back() = true;
  // mBitset[EVENT].back() = true;
  // mBitset[HITBOX].back() = true;
  mBitset[LIFE].back() = true;
  mBitset[POSITION].back() = true;
  mBitset[SHOOT].back() = true;
  mBitset[SPRITE].back() = true;
  // mBitset[TARGET].back() = true;

  mDynamics.push_back(Dynamics());
  mEvent.push_back(Event());
  mLife.push_back(Life(20));
  mPosition.push_back(Position(0, 0));
  Sprite enemySprite("../sprite/enemyShip.png");
  mSprite.push_back(enemySprite);
  TargetType target = NOTARGET;
  mTarget.push_back(target);
  mEntityType.push_back(ENEMYSHIP);
}

// the position pos is the center of the bullet
void World::createBullet(Position& pos) {
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

  mDynamics.push_back(Dynamics());
  mEvent.push_back(Event());
  mLife.push_back(Life(5));
  // @todo change position relative to player
  Sprite bulletSprite("../sprite/bulletPlayer.png");
  float X = pos.x() - bulletSprite.getSizeX()/2;
  float Y = pos.y() - bulletSprite.getSizeY()/2;
  mPosition.push_back(Position(X, Y));
  mSprite.push_back(bulletSprite);
  TargetType target = ENEMY;
  mTarget.push_back(target);
  mEntityType.push_back(BULLET);
}

void World::createEntity() {
  for (int i = 0; i < COMPONENTNUMBER; ++i)
    mBitset[i].push_back(false);
}


std::vector<bool>& World::getBitset(ComponentType type) {
  return mBitset[type];
}

Sprite& World::getSprite(int ind) {
  return mSprite[ind];
}

Position& World::getPosition(int ind) {
  return mPosition[ind];
}

Event& World::getEvent(int ind) {
  return mEvent[ind];
}

Dynamics& World::getDynamic(int ind) {
  return mDynamics[ind];
}

// what happens after 600 hours of play ?
int World::getTime() {
  return mClock.getElapsedTime().asMilliseconds();
}

EntityType& World::getEntityType(int ind) {
  return mEntityType[ind];
}
