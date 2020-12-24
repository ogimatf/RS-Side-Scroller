#include "FinalBossBullet2.h"
#include <iostream>
#include "Game.h"
#include "Block.h"
#include "Enemy.h"
#include <QList>

FinalBossBullet2::FinalBossBullet2(Direction dir) : EnemyProjectile()
{
    this->dir = dir;
    speed = 4;
    damage = 4;
    setPixmap(QPixmap(":/images/Textures/pick_01.png"));

}
void FinalBossBullet2::animate(){
    // TODO
    // Implementirati animaciju za bullet
}
void FinalBossBullet2::advance(){

    animation_parameter += 3;

    if(animation_parameter > 100)
        animation_parameter = 0;

    if( dir == LEFT){
         setPos(x() - speed, y());
    }
    else {
         setPos(x() + speed, y());
    }
    solveCollisions();
}
