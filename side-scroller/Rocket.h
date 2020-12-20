#ifndef ROCKET_H
#define ROCKET_H

#include "Projectile.h"

class Rocket: public Projectile
{

public:
    Rocket(Direction dir);

    virtual std::string name(){return "Rocket";}


    virtual void animate();

    virtual void advance();
};


#endif // ROCKET_H
