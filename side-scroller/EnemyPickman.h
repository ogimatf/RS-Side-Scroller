#ifndef ENEMYPICKMAN_H
#define ENEMYPICKMAN_H

#include "Enemy.h"

class EnemyPickman : public Enemy
{
public:
    EnemyPickman();
    virtual std::string name(){return "Pickman";}
    virtual void animate();
};

#endif // ENEMYPICKMAN_H
