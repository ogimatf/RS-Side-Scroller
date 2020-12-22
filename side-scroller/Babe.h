#ifndef BABE_H
#define BABE_H

#include "Entity.h"
class Babe : public Entity
{
public:
    Babe();
    bool player_close;

    virtual std::string name(){return "Babe";}
    virtual void advance();
    virtual void animate();
    virtual void damageBabe(int damage);
    virtual void lookForPlayer();
};

#endif // BABE_H
