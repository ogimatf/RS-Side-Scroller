#include "Rocket.h"
#include "Game.h"
#include "Enemy.h"

Rocket::Rocket(Direction dir) : Projectile()
{
    this->dir = dir;
    speed = 4;
    damage = 3;

    if(dir == LEFT)
    {
        setPixmap(QPixmap(":/images/Textures/rocket.png"));
    }
    else
    {
        setPixmap(QPixmap(":/images/Textures/rocket.png").transformed(QTransform().scale(-1,1)));
    }
}

void Rocket::animate(){

}

void Rocket::advance(){

    if( dir == LEFT){
         setPos(x() - speed, y());
    }
    else {
         setPos(x() + speed, y());
    }
    solveCollisions();
}


