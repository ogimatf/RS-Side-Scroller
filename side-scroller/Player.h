#pragma once

#include "Entity.h"

class Player : public Entity {
protected:
    static const int jump_duration_small = 80;
    static const int walk_div = 6;
    static const int running_div = 4;

    bool running;
public:
    Player(QPoint position);

    int x, y;
    QGraphicsRectItem* rect;

    void setRunning(bool _runing);
    virtual std::string name(){ return "Mario";}      
    virtual void animate();
    virtual void die();
    void jump();
};