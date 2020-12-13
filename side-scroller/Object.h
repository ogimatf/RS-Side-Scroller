#ifndef OBJECT_H
#define OBJECT_H

#include<QGraphicsRectItem>

#include "Utils.h"

class Object : public QGraphicsPixmapItem
{
    protected:

        bool walkable;
        bool collidable;

    public:

        Object();

        bool isWalkable()   {return walkable;  }
        bool isCollidable() {return collidable;}


        virtual std::string name() = 0;


        virtual void animate() = 0;

        virtual void advance() = 0;

        virtual void solveCollisions() = 0;
        virtual Direction collisionDirection(Object* item);
        virtual Direction touchingDirection(Object* item);
};
#endif // OBJECT_H
