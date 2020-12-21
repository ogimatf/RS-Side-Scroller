#ifndef SNIPERJOEBULLET_H
#define SNIPERJOEBULLET_H


#include "Projectile.h"

class SniperJoeBullet: public Projectile
{

public:
    SniperJoeBullet(Direction dir);

    virtual std::string name(){return "Sniper Joe's bullet";}

    virtual void animate();
    virtual void advance();
};

#endif // SNIPERJOEBULLET_H
