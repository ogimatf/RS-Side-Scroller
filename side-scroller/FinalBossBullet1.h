#ifndef FINALBOSSBULLET1_H
#define FINALBOSSBULLET1_H

#include "EnemyProjectile.h"

class FinalBossBullet1 : public EnemyProjectile
{

public:
    FinalBossBullet1(Direction dir);
    QPixmap texture[2];
    int animation_interval = 0;

    virtual std::string name(){return "Fireball";}

    virtual void animate();
    virtual void advance();
};

#endif // FINALBOSSBULLET1_H
