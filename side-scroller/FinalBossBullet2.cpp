#include "FinalBossBullet2.h"
#include "Block.h"
#include "Enemy.h"
#include "Game.h"
#include <QList>
#include <iostream>

FinalBossBullet2::FinalBossBullet2(Direction dir) : EnemyProjectile() {
  this->dir = dir;
  speed = 4;
  damage = 4;

  texture[0] = QPixmap(":/images/Textures/firewave_00.png");
  texture[1] = QPixmap(":/images/Textures/firewave_01.png");
  texture[2] = QPixmap(":/images/Textures/firewave_02.png");
}
void FinalBossBullet2::animate() {

  int animation_index;
  int tmp = animation_interval % 60;

  if (tmp < 20)
    animation_index = 0;
  else if (tmp >= 20 && tmp < 40)
    animation_index = 1;
  else
    animation_index = 2;

  setPixmap(texture[animation_index]);
}
void FinalBossBullet2::advance() {

  animation_interval++;


  if (dir == LEFT) {
    setPos(x() - speed, y());
  } else {
    setPos(x() + speed, y());
  }
  solveCollisions();
}
