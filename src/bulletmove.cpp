#include "bulletmove.hpp"
#include "world.hpp"

BulletMove::BulletMove() {
}

void BulletMove::run(World &world) {
  for (size_t i = 0; i < world.getBitset(TARGET).size(); ++i) {
    if (world.getBitset(DYNAMICS)[i]) {
      world.getDynamic(i).moveV(world.getPosition(i));

      auto& s = world.getSprite(i);
      auto& pos = world.getPosition(i);

      // if bullet outside view
      if ((pos.y() + s.getSizeY() < 0) ||
          (pos.y() > WINDOW_HEIGHT)    ||
          (pos.x() + s.getSizeX() < 0) ||
          (pos.x() > WINDOW_WIDTH)) {
        world.removeEntity(i);
        for (int j = 0; j < COMPONENTNUMBER; ++j)
          world.getBitset((ComponentType)j)[i] = false;

        world.getEntityType(i) = NOTDEFINED;
      }
    }
  }
}

