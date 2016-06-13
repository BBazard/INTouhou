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

            auto hBullet = world.getHitbox(i);
            auto hEnemy = world.getHitbox(j);
            hBullet.setPosition(posBullet);
            hEnemy.setPosition(posShip);

            sf::FloatRect r1(hEnemy.x(), hEnemy.y(), hEnemy.w(), hEnemy.h());
            sf::FloatRect r2(hBullet.x(), hBullet.y(), hBullet.w(), hBullet.h());

            if (r1.intersects(r2)) {
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
