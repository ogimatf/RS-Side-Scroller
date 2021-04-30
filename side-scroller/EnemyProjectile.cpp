#include "EnemyProjectile.h"
#include "Babe.h"
#include "Player.h"
EnemyProjectile::EnemyProjectile() : Projectile() {
    speed = 0;
    damage  = 0;
    dir = UNKNOWN;
}

void EnemyProjectile::solveCollisions() {
  QList<QGraphicsItem *> colliding_items = collidingItems();
  for (auto &ci : colliding_items) {
    Object *obj = dynamic_cast<Object *>(ci);
    if (!obj)
      continue;
    if (!obj->isCollidable()) {
      continue;
    }

    Player *player = dynamic_cast<Player *>(obj);
    if (player && !player->isDead()) {
      player->damagePlayer(this->damage);
    }
    Babe *princess_obj = dynamic_cast<Babe *>(obj);
    if (princess_obj && !princess_obj->isDead()) {
      princess_obj->damageBabe(this->damage);
    }
    delete this;
    break;
  }
}
