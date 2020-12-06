#pragma once

#include "Object.h"

// Entity object are "living", i.e. they can move, animate, fall,
// jump, collide, die, etc.
class Entity : public Object
{
    protected:

		// physics parameters
		int moving_speed;					// moving speed (pixels/frame)
	
		int jumping_speed;					// jumping speed (pixels/frame)
		int jumping_duration;				// jump duration (frames)

		// flags
		Direction dir;						// the direction of moving
        bool moving;						// is moving?
        bool jumping;						// is jumping?
        bool falling;						// is falling (gravity)?
		bool dying;							// dying / scheduled for death / death in progress
		bool dead;							// 100% dead
		bool freezed;						// cannot temporarily move

        // counters
        int jump_counter;					// counts the number of frames since jump started
		int death_counter;					// counts the number of frames since death
		int walk_counter;					// used for walking (main) animation cycle
		int freeze_counter;					// counts the number of frames since freeze started

		// durations (= limits for counters)
		int falling_speed;					// falling speed
		int death_duration;					// death duration (frames) before disappearing

		int freeze_duration;				// freeze duration (frames) before back to normal state

        // others
        QPointF prevPos;                    // previous position
		
        // utility methods
        virtual void startJumping();
        virtual void endJumping();

    public:

        Entity();

		// getters and setters
		bool isDead(){return dead;}
		bool isDying(){return dying;}
		bool isFalling() {return falling;}
		virtual void setDirection(Direction _dir) { dir = _dir;}
		virtual void setMoving(bool _moving) { if(!dying) moving = _moving;}

        // pure virtual methods to be implemented
        virtual std::string name()     = 0;
        virtual void animate()         = 0;
        virtual void advance();
    
		// die method, performs common operations to all entities
		// but it will need be overridden in some cases
		virtual void die();

		// freeze method
		virtual void freeze(){ freezed = true;}
};
