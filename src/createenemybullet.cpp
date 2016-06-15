#include "createenemybullet.hpp"
#include "world.hpp"

CreateEnemyBullet::CreateEnemyBullet() : mLastTime(0), mTimeBetweenBullet(800) {
}

void CreateEnemyBullet::run(World &world) {
  if (world.getTime() > mLastTime + mTimeBetweenBullet) {
    while (world.getTime() > mLastTime + mTimeBetweenBullet)
      mLastTime += mTimeBetweenBullet;
    for (size_t i = 0; i < world.getBitset(DYNAMICS).size(); ++i) {
      if (world.getEntityType(i) == ENEMYSHIP) {
        int x = world.getPosition(i).x() + world.getSprite(i).getSizeX()/2;
        int y = world.getPosition(i).y() + world.getSprite(i).getSizeY();
        Position b(x, y);
        if (world.getLife(i).getLife() > 150) {
          world.createBullet(b, "../sprite/bulletEnemy.png", PLAYER, PATTERN1);
          world.createBullet(b, "../sprite/bulletEnemy.png", PLAYER, PATTERN2);
        } else if (world.getLife(i).getLife() > 100) {
            mTimeBetweenBullet = 600;
            world.createBullet(b, "../sprite/enemyBullet2.png", PLAYER, PATTERN3);
            world.createBullet(b, "../sprite/enemyBullet2.png", PLAYER, PATTERN4);
          } else {
              mTimeBetweenBullet = 1000;
              world.createBullet(b, "../sprite/bulletEnemy.png", PLAYER, PATTERN1);
              world.createBullet(b, "../sprite/bulletEnemy.png", PLAYER, PATTERN2);
              world.createBullet(b, "../sprite/enemyBullet2.png", PLAYER, PATTERN3);
              world.createBullet(b, "../sprite/enemyBullet2.png", PLAYER, PATTERN4);
            }
      }
    }
  }
}
