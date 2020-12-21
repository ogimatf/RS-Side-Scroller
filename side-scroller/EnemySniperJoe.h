#ifndef ENEMYSNIPERJOE_H
#define ENEMYSNIPERJOE_H

#include "Enemy.h"

class EnemySniperJoe : public Enemy
{
public:
    EnemySniperJoe();

    virtual std::string name(){return "Sniper Joe";}
    virtual void animate();
    virtual void enemyShoot();
};

#endif // ENEMYSNIPERJOE_H
