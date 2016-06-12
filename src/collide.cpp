#include "collide.hpp"
#include "world.hpp"

Collide::Collide() {

}

void Collide::run(World &world) {
  for (size_t i = 0; i < world.getBitset(TARGET).size(); ++i) {
    if (world.getBitset(TARGET)[i]) {
      if (world.getTarget(i).getTarget() == ENEMY) {
        for (size_t j = 0; j < world.getBitset(HITBOX).size(); ++j) {
          if (world.getEntityType(j) == ENEMYSHIP) {
            auto posBullet = world.getPosition(i);
            auto posShip = world.getPosition(j);

//            world.getHitbox(i).setPosition(posBullet);
//            world.getHitbox(j).setPosition(posShip);

            if (posBullet.y() > posShip.y() &&
                posBullet.y() < posShip.y() + world.getSprite(j).getSizeY()) {
              world.removeEntity(i);
              world.getLife(j).decreaseLife();
              if (world.getLife(j).getLife() < 1)
                world.removeEntity(j);
            }
          }
        }
      }
    }
  }
}
