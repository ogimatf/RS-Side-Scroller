#include "Projectile.h"
#include "Babe.h"
#include "Enemy.h"

Projectile::Projectile() : Object() {
  collidable = false;
  damage = 0;
  speed = 0;
  dir = UNKNOWN;
}

void Projectile::solveCollisions() {

  QList<QGraphicsItem *> colliding_items = collidingItems();

  for (auto &ci : colliding_items) {

    Object *obj = dynamic_cast<Object *>(ci);

    if (!obj)
      continue;
    if (!obj->isCollidable()) {
      continue;
    }

    Enemy *entity_obj = dynamic_cast<Enemy *>(obj);
    if (entity_obj && !entity_obj->isDead()) {
      entity_obj->damageEnemy(this->damage);
    }

    Babe *princess_obj = dynamic_cast<Babe *>(obj);
    if (princess_obj && !princess_obj->isDead()) {
      princess_obj->damageBabe(this->damage);
    }

    delete this;
    break;
  }
}
