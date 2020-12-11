#include "Entity.h"
#include "Game.h"


Entity::Entity() : Object()
{
    // physics parameters
    moving_speed     = 1;
    jumping_speed    = 2;
    falling_speed    = 2;

    // flags
    dir     = RIGHT;
    moving  = true;
    jumping = false;
    falling = true;		// we can create entities in mid air and they will fall
    dying   = false;
    dead    = false;
    freezed = false;

    collectable = false;

    // counters
    jump_counter    = 0;
    death_counter   = 0;
    walk_counter    = 0;
    freeze_counter	= 0;

    // durations
    jumping_duration = 30;
    death_duration   = 100;
    freeze_duration  = 80;

    // others
    walkable_object = 0;
}

void Entity::startJumping()
{
    // entity can jump only when it is not falling
    if(!falling && !jumping)
    {
        walkable_object = 0;
        jumping = true;
    }
}

void Entity::endJumping()
{
    if(jumping)
    {
        jumping = false;
        jump_counter = 0;
        falling = true;
    }
}

void Entity::advance()
{
    // NOTE: every movement is embedded in a prevPos = pos() ... solveCollisions() block

    // do nothing if object is freezed
    if(freezed)
    {
        freeze_counter++;
        if(freeze_counter > freeze_duration)
        {
            freezed = false;
            freeze_counter = 0;
        }
        else
            return;
    }

    // moving
    if(moving)
    {

        prevPos = pos();


        if(dir == RIGHT)
            setX(x() + moving_speed);
        else if(dir == LEFT)
            setX(x() - moving_speed);
        else if(dir == UP)
            setY(y() - moving_speed);
        else if(dir == DOWN)
            setY(y() + moving_speed);

    }

    // jumping
    if(jumping)
    {
        prevPos = pos();

        // move upwards
        setY(y() - jumping_speed);

        // increase jump frame count
        jump_counter += jumping_speed;

        // end jumping when frame count reaches the defined limit
        if(jump_counter > jumping_duration)
            endJumping();
    }

    // if the entity is not touching its walkable object anymore
    // we have to start falling
    // if(walkable_object && !touchingDirection(walkable_object))
        // falling = true;

    // falling
    if(falling)
    {
        prevPos = pos();

        setY(y() + falling_speed);

    }

    // if we fall beyond the scene bottom limit
    // we have to die (if not dead already)
    if(y() > Game::instance()->getScene()->sceneRect().height() - 50 && !dying)
        // die();
    {
        falling = false;
        setY(400);
    }


    // if dying, increase death counter
    // and set dead if counter exceeds death duration
    if(dying)
    {
        death_counter++;
        if(death_counter > death_duration)
            dead = true;
    }
}


void Entity::die()
{
    // only a full living entity can die
    if(!dying && !dead)
    {
        // scheduled for death
        dying = true;

        // start death counter
        death_counter = 0;

        // cannot move
        moving = false;
    }
}
