#ifndef FINALBOSSBULLET1_H
#define FINALBOSSBULLET1_H

#include "EnemyProjectile.h"

class FinalBossBullet1 : public EnemyProjectile
{

public:
    FinalBossBullet1(Direction dir);

    virtual std::string name(){return "Sniper Joe's bullet";}

    virtual void animate();
    virtual void advance();
};

#endif // FINALBOSSBULLET1_H
