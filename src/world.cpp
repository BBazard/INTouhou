#include "world.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

World::World() :
  mWindow(sf::VideoMode(600, 800), "INTouhou"),
  mDisplay(mWindow) {
  // // entity number 0 is empty
  for (int i = 0; i < COMPONENTNUMBER; ++i)
    mBitset.push_back(std::vector<bool>());

  //for (int i = 0; i < COMPONENTNUMBER; ++i)
    //mBitset[i].push_back(false);

  //for (auto n : mBitset[0])
    //n = false;

   //mAnimation.push_back();
   //mDynamics.push_back();
   //mEvent.push_back();
   //mHitbox.push_back();
   //mLife.push_back(Life(0));
   //mPosition.push_back(Position(0, 0));
   //mShoot.push_back();
   //mSprite.push_back(Sprite("nofile"));
   //mTarget.push_back();
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
    sf::Event event;
    while (mWindow.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        mWindow.close();
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        mWindow.close();
    }
    mDisplay.run(*this);
  }
}

void World::createPlayer() {
  createEntity();

  // mBitset[ANIMATION].back() = true;
  // mBitset[DYNAMICS].back() = true;
  //mBitset[EVENT].back() = true;
  //mBitset[HITBOX].back() = true;
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
}

void World::createEnemy() {
  createEntity();

  // mBitset[ANIMATION].back() = true;
  // mBitset[DYNAMICS].back() = true;
  // mBitset[EVENT].back() = true;
  //mBitset[HITBOX].back() = true;
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
  //mBitset[HITBOX].back() = true;
  // mBitset[LIFE].back() = true;
  mBitset[POSITION].back() = true;
  // mBitset[SHOOT].back() = true;
  mBitset[SPRITE].back() = true;
  // mBitset[TARGET].back() = true;
}

void World::createEntity() {
 // for (unsigned long i = 0; i < mBitset.size(); ++i)
 //   for (auto n : mBitset[i])
 //     n = false;
  //mBitset.push_back(std::vector<bool>(false));

  for (int i = 0; i < COMPONENTNUMBER; ++i)
    mBitset[i].push_back(false);
}

std::vector<bool> World::getBitset(ComponentType type) {
  return mBitset[type];
}

std::vector<Sprite> World::getSprites() {
  return mSprite;
}

std::vector<Position> World::getPositions() {
  return mPosition;
}
