#include "createenemybullet.hpp"
#include "world.hpp"

CreateEnemyBullet::CreateEnemyBullet() {
}

void CreateEnemyBullet::run(World &world) {
  int timeBetweenBullet = 500;  //  millisecond
  if (world.getTime() > mLastTime + timeBetweenBullet) {
    mLastTime += timeBetweenBullet;
    for (size_t i = 0; i < world.getBitset(DYNAMICS).size(); ++i) {
      if (world.getEntityType(i) == ENEMYSHIP) {
        int x = world.getPosition(i).x() + world.getSprite(i).getSizeX()/2;
        int y = world.getPosition(i).y() + world.getSprite(i).getSizeY();
        Position b(x, y);
        world.createBullet(b, "../sprite/bulletEnemy.png", PLAYER);
      }
    }
  }
}
