#include "SniperJoeBullet.h"
#include "Block.h"
#include "Enemy.h"
#include "Game.h"
#include <QList>
#include <iostream>

SniperJoeBullet::SniperJoeBullet(Direction dir) : EnemyProjectile()
{
    this->dir = dir;
    speed = 5;
    damage = 2;
    setPixmap(QPixmap(":/images/Textures/sniper_bullet_01.png"));

}
void SniperJoeBullet::animate(){

}
void SniperJoeBullet::advance(){

    if( dir == LEFT){
         setPos(x() - speed, y());
    }
    else {
         setPos(x() + speed, y());
    }
    solveCollisions();
}
