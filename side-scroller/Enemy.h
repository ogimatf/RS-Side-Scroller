#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity
{
public:
    Enemy();
    int health;
    int damage;
    int enemy_shooting_interval = 0;

    virtual std::string name() = 0;
    virtual void enemyShoot();
    virtual void animate() = 0;
    virtual void damageEnemy(int damage);
};

#endif // ENEMY_H
