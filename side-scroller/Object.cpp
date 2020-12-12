#include "Object.h"
#include "Game.h"

Object::Object() : QGraphicsPixmapItem(0)
{
    collidable = true;
    walkable   = false;

    setShapeMode(QGraphicsPixmapItem::BoundingRectShape);

    Game::instance()->getScene()->addItem(this);
}
