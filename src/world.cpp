#include "world.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cassert>

World::World() :
  mWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "INTouhou"),
  mDisplay(mWindow),
  mKeyController(mWindow) {
  mWindow.setKeyRepeatEnabled(false);
  mWindow.setFramerateLimit(60);
  // entity number 0 is player
  for (int i = 0; i < COMPONENTNUMBER; ++i)
    mBitset.push_back(std::vector<bool>());
}

void World::createBomb() {
  int i = getNextUnusedIndex();
  mEntityType[i] = BOMB;

  mBitset[POSITION][i] = true;
  mBitset[SPRITE][i] = true;

  mPosition[i].setX(0);
  mPosition[i].setY(0);

  mSprite[i].set("../sprite/vaisseau.png");
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
  int i = getNextUnusedIndex();

  mBitset[EVENT][i] = true;
  mBitset[LIFE][i] = true;
  mBitset[POSITION][i] = true;
  mBitset[SPRITE][i] = true;

  mEvent[i].EmptyDirection();
  mLife[i].setLife(5);
  // @todo change 200 with display
  mPosition[i].setX(WINDOW_WIDTH/2 - 40);
  mPosition[i].setY(5*WINDOW_HEIGHT/6);
  mSprite[i].set("../sprite/vaisseau.png");
  TargetType tt = NOTARGET;
  mTarget[i].setTarget(tt);
  mEntityType[i] = PLAYERSHIP;
}

void World::createEnemy() {
  int i = getNextUnusedIndex();

  mBitset[LIFE][i] = true;
  mBitset[POSITION][i] = true;
  mBitset[SHOOT][i] = true;
  mBitset[SPRITE][i] = true;

  mEvent[i].EmptyDirection();
  mLife[i].setLife(20);
  mPosition[i].setX(0);
  mPosition[i].setY(0);
  mSprite[i].set("../sprite/enemyShip.png");
  TargetType tt = NOTARGET;
  mTarget[i].setTarget(tt);
  mEntityType[i] = ENEMYSHIP;
}

// the position pos is the center of the bullet
void World::createBullet(Position& pos) {
  int i = getNextUnusedIndex();

  mBitset[DYNAMICS][i] = true;
  mBitset[HITBOX][i] = true;
  mBitset[POSITION][i] = true;
  mBitset[SPRITE][i] = true;
  mBitset[TARGET][i] = true;

  mEvent[i].EmptyDirection();
  mLife[i].setLife(5);
  mSprite[i].set("../sprite/bulletPlayer.png");
  float X = pos.x() - mSprite[i].getSizeX()/2;
  float Y = pos.y() - mSprite[i].getSizeY()/2;
  mPosition[i].setX(X);
  mPosition[i].setY(Y);
  TargetType tt = ENEMY;
  mTarget[i].setTarget(tt);
  mEntityType[i] = BULLET;
  // mDynamics[i]
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

void World::removeEntity(int ind) {
  for (int i = 0; i < COMPONENTNUMBER; ++i)
    getBitset((ComponentType)i)[ind] = false;

  getEntityType(ind) = NOTDEFINED;
}

int World::getNextUnusedIndex() {
  for (int i = 0; i < COMPONENTNUMBER; ++i)
    assert(mEntityType.size() == mBitset[(ComponentType)i].size());

  if (mEntityType.size() != 0) {
    for (size_t i = 0; i < mEntityType.size(); ++i)
      if (mEntityType[i] == NOTDEFINED)
        return i;
  }

  for (int i = 0; i < COMPONENTNUMBER; ++i)
    mBitset[(ComponentType)i].push_back(false);

  mDynamics.push_back(Dynamics());
  mEvent.push_back(Event());
  mLife.push_back(Life(1000));
  mPosition.push_back(Position(0, 0));
  mSprite.push_back(Sprite());
  mSprite.back().set("../sprite/bulletPlayer.png");
  TargetType target = NOTARGET;
  mTarget.push_back(target);
  mEntityType.push_back(NOTDEFINED);

  return (mEntityType.size() - 1);
}

