#ifndef FINALBOSSBULLET2_H
#define FINALBOSSBULLET2_H

#include "EnemyProjectile.h"

class FinalBossBullet2: public EnemyProjectile
{

public:
    FinalBossBullet2(Direction dir);

    int animation_parameter = 0;

    virtual std::string name(){return "Pickaxe";}

    virtual void animate();
    virtual void advance();
};

#endif// FINALBOSSBULLET2_H
