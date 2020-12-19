#include "Rocket.h"
#include "Game.h"
Rocket::Rocket(Direction dir) : Projectile()
{
    this->dir = dir;
    speed = 4;
    damage = 3;
    setPixmap(QPixmap(":/images/rocket.png"));
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
void Rocket::solveCollisions(){
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

