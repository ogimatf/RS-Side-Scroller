#pragma once

#include <string>
#include <QGraphicsPixmapItem>

#include "utils.h"

// base class for all game objects
class Object : public QGraphicsPixmapItem
{	
	protected:

		bool walkable;		// whether the object is walkable
		bool collidable;	// whether the object is collidable

	public:

		Object();

		// getters
		bool isWalkable()   {return walkable;  }
		bool isCollidable() {return collidable;}

        // object name
		virtual std::string name() = 0;

        // animate (=compute next texture)
        virtual void animate() = 0;

        // advance (=compute next location)
        virtual void advance() = 0;

};
