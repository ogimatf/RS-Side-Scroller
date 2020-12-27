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
    texture[0] = QPixmap(":/images/Textures/fire_ball_00.png");
    texture[1] = QPixmap(":/images/Textures/fire_ball_01.png");

    setPixmap(texture[0]);

}
void FinalBossBullet1::animate(){

    int animation_index = animation_interval % 40 < 20 ? 0 : 1;

    setPixmap(texture[animation_index]);

}
void FinalBossBullet1::advance(){

    animation_interval++;

    if( dir == LEFT){
         setPos(x() - speed, y());
    }
    else {
         setPos(x() + speed, y());
    }
    solveCollisions();
}
