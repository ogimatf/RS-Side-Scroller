#include "EnemyProjectile.h"
#include "Player.h"
EnemyProjectile::EnemyProjectile() : Projectile()
{


}

void EnemyProjectile::solveCollisions(){
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(auto& ci : colliding_items){
        Object* obj = dynamic_cast<Object*>(ci);
        if(!obj)
            continue;
        if(!obj->isCollidable()){
            continue;
        }

        Player* player = dynamic_cast<Player*>(obj);
        if(player && !player->isDead()){
            player->damagePlayer(this->damage);
        }
        delete this;
        break;
    }
}
