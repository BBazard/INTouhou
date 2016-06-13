#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "component.hpp"
#include "system.hpp"
#include "life.hpp"
#include "sprite.hpp"
#include "position.hpp"
#include "display.hpp"
#include "event.hpp"
#include "playermove.hpp"
#include "keycontroller.hpp"
#include "bulletmove.hpp"
#include "target.hpp"
#include "dynamics.hpp"
#include "createPlayerBullet.hpp"
#include "enemymove.hpp"
#include "collide.hpp"
#include "hitbox.hpp"

/**
 * @brief
 *
 *
 */
class World {
 private:
  sf::RenderWindow mWindow;
  // systems
  Display mDisplay;
  PlayerMove mPlayerMove;
  KeyController mKeyController;
  BulletMove mBulletMove;
  CreatePlayerBullet mCreatePlayerBullet;
  EnemyMove mEnemyMove;
  Collide mCollide;

  // std::vector<Animation> mAnimation;
  std::vector<Dynamics> mDynamics;
  std::vector<Event> mEvent;
  std::vector<Hitbox> mHitbox;
  std::vector<Life> mLife;
  std::vector<Position> mPosition;
  // std::vector<Shoot> mShoot;
  std::vector<Sprite> mSprite;
  std::vector<Target> mTarget;

  std::vector<EntityType> mEntityType;  //  Not defined in the mBitset vector

  std::vector<std::vector<bool>> mBitset;

  sf::Clock mClock;
  sf::Music mMusic;

 public:
  World();
  void createBomb();
  void createBullet(Position &pos);
  void createEnemy();
  void createPlayer();
  void run();

  std::vector<bool>& getBitset(ComponentType type);
  Sprite& getSprite(int ind);
  Position& getPosition(int ind);
  Event& getEvent(int ind);
  Dynamics& getDynamic(int ind);
  int getTime();
  EntityType& getEntityType(int ind);
  void removeEntity(int ind);
  Target& getTarget(int ind);
  Life& getLife(int ind);
  Hitbox& getHitbox(int ind);

 private:
  int getNextUnusedIndex();
};
