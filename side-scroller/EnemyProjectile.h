#ifndef ENEMYPROJECTILE_H
#define ENEMYPROJECTILE_H

#include "Projectile.h"

class EnemyProjectile : public Projectile
{
public:
    EnemyProjectile();
    Direction dir;
    int speed;
    int damage;

    virtual std::string name() = 0;


    virtual void animate() = 0;

    virtual void advance() = 0;

    virtual void solveCollisions();
};

#endif // ENEMYPROJECTILE_H
