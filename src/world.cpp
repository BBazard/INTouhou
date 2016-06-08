#include "world.hpp"
#include <vector>

World::World() {
  mBitset.resize(COMPONENTNUMBER);
}

void World::createBomb() {
  createEntity();

  // mBitset.back()[ANIMATION] = true;
  // mBitset.back()[DYNAMICS] = true;
  // mBitset.back()[EVENT] = true;
  // mBitset.back()[HITBOX] = true;
  // mBitset.back()[LIFE] = true;
  mBitset.back()[POSITION] = true;
  // mBitset.back()[SHOOT] = true;
  mBitset.back()[SPRITE] = true;
  // mBitset.back()[TARGET] = true;
}

void World::createPlayer() {
  createEntity();

  // mBitset.back()[ANIMATION] = true;
  // mBitset.back()[DYNAMICS] = true;
  mBitset.back()[EVENT] = true;
  mBitset.back()[HITBOX] = true;
  mBitset.back()[LIFE] = true;
  mBitset.back()[POSITION] = true;
  // mBitset.back()[SHOOT] = true;
  mBitset.back()[SPRITE] = true;
  // mBitset.back()[TARGET] = true;
}

void World::createEnemy() {
  createEntity();

  // mBitset.back()[ANIMATION] = true;
  // mBitset.back()[DYNAMICS] = true;
  // mBitset.back()[EVENT] = true;
  mBitset.back()[HITBOX] = true;
  mBitset.back()[LIFE] = true;
  mBitset.back()[POSITION] = true;
  // mBitset.back()[SHOOT] = true;
  mBitset.back()[SPRITE] = true;
  // mBitset.back()[TARGET] = true;
}

void World::createBullet() {
  createEntity();

  // mBitset.back()[ANIMATION] = true;
  // mBitset.back()[DYNAMICS] = true;
  // mBitset.back()[EVENT] = true;
  mBitset.back()[HITBOX] = true;
  // mBitset.back()[LIFE] = true;
  mBitset.back()[POSITION] = true;
  // mBitset.back()[SHOOT] = true;
  mBitset.back()[SPRITE] = true;
  // mBitset.back()[TARGET] = true;
}

void World::createEntity() {
  for (unsigned long i = 0; i < mBitset.size(); ++i)
    for (auto n : mBitset[i])
      n = false;
  mBitset.push_back(std::vector<bool>(false));
}

