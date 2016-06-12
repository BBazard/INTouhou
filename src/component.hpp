#pragma once

typedef enum {
  ANIMATION,
  DYNAMICS,
  EVENT,
  HITBOX,
  LIFE,
  POSITION,
  SHOOT,
  SPRITE,
  TARGET,
  COMPONENTNUMBER,
} ComponentType;

typedef enum {
  UP,
  DOWN,
  LEFT,
  RIGHT,
  NONE,
} Direction;

typedef enum {
  PLAYER,
  ENEMY,
  NOTARGET,
} TargetType;

typedef enum {
  PLAYERSHIP,
  ENEMYSHIP,
  BULLET,
  BOMB,
  NOTDEFINED,
} EntityType;

class Component {
 public:
 private:
};

