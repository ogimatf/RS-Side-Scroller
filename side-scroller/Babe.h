#ifndef BABE_H
#define BABE_H

#include "Entity.h"
class Babe : public Entity
{
public:
    Babe();
    bool player_close;

    QPixmap texture_dying[4];

    int dc_1 = 25;
    int dc_2 = 50;
    int dc_3 = 75;

    int  death_ind = 0;

    virtual std::string name(){return "Babe";}
    virtual void advance();
    virtual void animate();
    virtual void damageBabe(int damage);
    virtual void lookForPlayer();
};

#endif // BABE_H
