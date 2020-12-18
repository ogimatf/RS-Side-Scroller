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
    QPixmap texture_jump;

    bool running;
public:
    Player(QPoint position);

    int x, y;
//    QGraphicsPixmapItem* rect;

    void setRunning(bool _runing);
    virtual std::string name(){ return "Mega Man";}
    virtual void animate();
    virtual void die();
    void jump();
};

#endif // PLAYER_H
