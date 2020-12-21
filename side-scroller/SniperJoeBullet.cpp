#include "SniperJoeBullet.h"
#include <iostream>
#include "Game.h"
#include "Block.h"
#include "Enemy.h"
#include <QList>

SniperJoeBullet::SniperJoeBullet(Direction dir) : Projectile()
{
    this->dir = dir;
    speed = 5;
    damage = 1;
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
