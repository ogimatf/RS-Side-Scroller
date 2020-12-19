#ifndef ENTITY_H
#define ENTITY_H

#include "Object.h"

class Entity : public Object
{
    protected:
        int moving_speed;

        int jumping_speed;
        int jumping_duration;

        // flags
        Direction dir;
        bool moving;
        bool jumping;
        bool falling;
        bool collectable;
        bool dying;
        bool dead;
        bool freezed;


        int jump_counter;
        int death_counter;
        int walk_counter;
        int freeze_counter;


        int falling_speed;
        int death_duration;

        int freeze_duration;

        QPointF prevPos;
        Object *walkable_object;

        virtual void startJumping();
        virtual void endJumping();

    public:

        Entity();

        Direction getDir(){return dir;}
        bool isDead(){return dead;}
        bool isDying(){return dying;}
        bool isCollectable() { return collectable;}
        bool isFalling() {return falling;}
        virtual void setDirection(Direction _dir) { dir = _dir;}
        virtual void setMoving(bool _moving) { if(!dying) moving = _moving;}

        virtual std::string name()     = 0;
        virtual void animate()         = 0;
        virtual void advance();


        virtual void die();
        virtual void solveCollisions();
        virtual void freeze(){ freezed = true;}
};

#endif // ENTITY_H
