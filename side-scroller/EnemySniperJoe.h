#ifndef ENEMYSNIPERJOE_H
#define ENEMYSNIPERJOE_H

#include "Enemy.h"

class EnemySniperJoe : public Enemy
{
public:
    EnemySniperJoe();

    QPixmap texture_idle;
    QPixmap texture_shooting[2];

    virtual std::string name(){return "Sniper Joe";}
    virtual void animate();
    virtual void enemyShoot();
};

#endif // ENEMYSNIPERJOE_H
