#include "Rocket.h"
#include "Game.h"
#include "Enemy.h"
Rocket::Rocket(Direction dir) : Projectile()
{
    this->dir = dir;
    speed = 4;
    damage = 3;
    setPixmap(QPixmap(":/images/Textures/rocket.png"));
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


