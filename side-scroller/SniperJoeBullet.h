#ifndef SNIPERJOEBULLET_H
#define SNIPERJOEBULLET_H


#include "EnemyProjectile.h"

class SniperJoeBullet: public EnemyProjectile
{

public:
    SniperJoeBullet(Direction dir);

    virtual std::string name(){return "Sniper Joe's bullet";}

    virtual void animate();
    virtual void advance();
};

#endif // SNIPERJOEBULLET_H
