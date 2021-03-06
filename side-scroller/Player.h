#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <QGraphicsPixmapItem>

class Player : public Entity {
protected:
    static const int jump_duration = 90;
    static const int walk_div = 6;
    static const int running_div = 4;

    QPixmap texture_walk[3];
    QPixmap texture_stand;
    QPixmap texture_jump[2];
    QPixmap texture_stand_shoot;
    QPixmap texture_jump_shoot[2];
    QPixmap texture_walk_shoot[3];
    QPixmap texture_dying[4];

    bool running;
    int  death_ind = 0;
public:
    Player(QPoint position);

    int x, y;
    int bullet_interval;
    int rocket_interval;

    bool won = false;

//    QGraphicsPixmapItem* rect;

    void setRunning(bool _runing);
    virtual std::string name(){ return "Mega Man";}
    virtual void animate();
    virtual void damagePlayer(int damage);
    void jump();
};

#endif // PLAYER_H
