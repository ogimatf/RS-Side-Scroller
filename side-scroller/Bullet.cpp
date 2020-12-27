#include "Bullet.h"
#include <iostream>
#include "Game.h"
#include "Block.h"
#include "Enemy.h"
#include <QList>

Bullet::Bullet(Direction dir) : Projectile()
{
    this->dir = dir;
    speed = 5;
    damage = 1;
    setPixmap(QPixmap(":/images/Textures/bullet.png"));

}
void Bullet::animate(){

}

void Bullet::advance(){

    if( dir == LEFT){
         setPos(x() - speed, y());
    }
    else {
         setPos(x() + speed, y());
    }
    solveCollisions();
}


