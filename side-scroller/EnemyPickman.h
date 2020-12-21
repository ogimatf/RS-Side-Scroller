#ifndef ENEMYPICKMAN_H
#define ENEMYPICKMAN_H

#include "Enemy.h"

class EnemyPickman : public Enemy
{
public:
    EnemyPickman();

    QPixmap texture_idle;
    QPixmap texture_shooting[2];

    virtual std::string name(){return "Pickman";}
    virtual void animate();
    virtual void enemyShoot();
};

#endif // ENEMYPICKMAN_H
