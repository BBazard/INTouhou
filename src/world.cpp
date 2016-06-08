#include "world.hpp"

World::World() {
  mBitset.resize(COMPONENTNUMBER);
}

void World::createPlayer() {
  for (unsigned long i = 0; i < mBitset.size(); ++i)
    for (auto n : mBitset[i])
      n = false;

  mBitset.push_back(std::vector<bool>(false));
  mBitset.back()[LIFE] = false;
  mBitset.back()[POSITION] = true;
}


