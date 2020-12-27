#ifndef ENEMYFINALBOSS_H
#define ENEMYFINALBOSS_H

#include "Enemy.h"

class EnemyFinalBoss : public Enemy
{
public:
    EnemyFinalBoss();

    QPixmap texture_idle[2];
    QPixmap texture_shooting_fireball[2];
    QPixmap texture_shooting_firewave[2];
    QPixmap texture_dying[4];

    int death_ind = 0;
    int fire_counter = 0;
    int shooting_style = 1;

    bool invulnerable = false;

    virtual std::string name(){return "Final Boss";}
    virtual void animate();
    virtual void enemyShoot();
    virtual void damageEnemy(int damage);
};

#endif// ENEMYFINALBOSS_H
