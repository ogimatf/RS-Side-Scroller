#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Object.h"

class Projectile : public Object
{
public:
    Projectile();
    Direction dir;
    int speed;
    int damage;

    virtual std::string name() = 0;


    virtual void animate() = 0;

    virtual void advance() = 0;

    virtual void solveCollisions() = 0;
};

#endif // PROJECTILE_H
