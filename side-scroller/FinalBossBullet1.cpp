#include "FinalBossBullet1.h"
#include <iostream>
#include "Game.h"
#include "Block.h"
#include "Enemy.h"
#include <QList>

FinalBossBullet1::FinalBossBullet1(Direction dir) : EnemyProjectile()
{
    this->dir = dir;
    speed = 6;
    damage = 2;
    setPixmap(QPixmap(":/images/Textures/sniper_bullet_01.png"));

}
void FinalBossBullet1::animate(){

}
void FinalBossBullet1::advance(){

    if( dir == LEFT){
         setPos(x() - speed, y());
    }
    else {
         setPos(x() + speed, y());
    }
    solveCollisions();
}
