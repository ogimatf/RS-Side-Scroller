#ifndef PICKAXE_H
#define PICKAXE_H

#include "EnemyProjectile.h"

class Pickaxe: public EnemyProjectile
{

public:
    Pickaxe(Direction dir);

    int animation_parameter = 0;

    virtual std::string name(){return "Pickaxe";}

    virtual void animate();
    virtual void advance();
};

#endif // PICKAXE_H
