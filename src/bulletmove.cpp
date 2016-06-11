#include "bulletmove.hpp"
#include "world.hpp"

BulletMove::BulletMove() {
}

void BulletMove::run(World &world) {
  for (size_t i = 0; i < world.getBitset(TARGET).size(); ++i) {
    if (world.getBitset(DYNAMICS)[i]) {
      world.getPositions(i).move(0, -2);
    }
  }
}
