#include "Bullet.h"
#include <iostream>
#include "Game.h"
#include "Block.h"
#include <QList>

Bullet::Bullet(Direction dir) : Projectile()
{
    this->dir = dir;
    speed = 5;
    damage = 1;
    setPixmap(QPixmap(":/images/bullet.png"));

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

void Bullet::solveCollisions(){
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(auto& ci : colliding_items){
        Object* obj = dynamic_cast<Object*>(ci);
        if(!obj)
            continue;
        if(!obj->isCollidable()){
            continue;
        }
        scene()->removeItem(this);
        delete this;
        break;
    }
}

