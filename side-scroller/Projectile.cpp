#include "Projectile.h"
#include "Enemy.h"

Projectile::Projectile() : Object()
{
    collidable = false;
}

void Projectile::solveCollisions(){
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(auto& ci : colliding_items){
        Object* obj = dynamic_cast<Object*>(ci);
        if(!obj)
            continue;
        if(!obj->isCollidable()){
            continue;
        }

        Enemy* entity_obj = dynamic_cast<Enemy*>(obj);
        if(entity_obj && !entity_obj->isDead()){
            entity_obj->damageEnemy(this->damage);
        }
        delete this;
        break;
    }
}
