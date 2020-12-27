#ifndef FINALBOSSBULLET2_H
#define FINALBOSSBULLET2_H

#include "EnemyProjectile.h"

class FinalBossBullet2: public EnemyProjectile
{

public:
    FinalBossBullet2(Direction dir);
    QPixmap texture[3];
    int animation_interval = 0;

    virtual std::string name(){return "Firewave";}

    virtual void animate();
    virtual void advance();
};

#endif// FINALBOSSBULLET2_H
