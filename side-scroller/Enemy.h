#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include <QSound>

class Enemy : public Entity
{
public:
    Enemy();
    int enemy_shooting_interval = 0;
    int enemy_animation_interval = 0;
    bool player_close;

    virtual std::string name() = 0;
    virtual void enemyShoot() = 0;
    virtual void advance();
    virtual void animate() = 0;
    virtual void damageEnemy(int damage);
    virtual void lookForPlayer();

};

#endif // ENEMY_H
