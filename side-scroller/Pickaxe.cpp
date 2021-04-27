#include "Pickaxe.h"
#include "Block.h"
#include "Enemy.h"
#include "Game.h"
#include <QList>
#include <iostream>

Pickaxe::Pickaxe(Direction dir) : EnemyProjectile() {
  this->dir = dir;
  speed = 5;
  damage = 1;
  setPixmap(QPixmap(":/images/Textures/pick_01.png"));
}
void Pickaxe::animate() {

  if (animation_parameter < 25)
    setPixmap(QPixmap(":/images/Textures/pick_01.png"));
  else if (animation_parameter > 25 && animation_parameter < 50)
    setPixmap(QPixmap(":/images/Textures/pick_02.png"));
  else if (animation_parameter > 50 && animation_parameter < 75)
    setPixmap(QPixmap(":/images/Textures/pick_03.png"));
  else
    setPixmap(QPixmap(":/images/Textures/pick_04.png"));
}
void Pickaxe::advance() {

  animation_parameter += 3;

  if (animation_parameter > 100)
    animation_parameter = 0;

  if (dir == LEFT) {
    setPos(x() - speed, y());
  } else {
    setPos(x() + speed, y());
  }
  solveCollisions();
}
