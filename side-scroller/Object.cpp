#include "Object.h"
#include "Game.h"

Object::Object() : QGraphicsPixmapItem(0)
{
	collidable = true;
	walkable   = false;

	// game mechanics are based on bounding rects 
	setShapeMode(QGraphicsPixmapItem::BoundingRectShape);

	// add to scene
	Game::instance()->getScene()->addItem(this);
}
