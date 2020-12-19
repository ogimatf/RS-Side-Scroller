#ifndef BULLET_H
#define BULLET_H

#include "Projectile.h"

class Bullet: public Projectile
{

public:
    Bullet(Direction dir);

    virtual std::string name(){return "Bullet";}


    virtual void animate();

    virtual void advance();

    virtual void solveCollisions();
};

#endif // BULLET_H
