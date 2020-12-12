#include "Entity.h"
#include "Game.h"


Entity::Entity() : Object()
{
    moving_speed     = 1;
    jumping_speed    = 2;
    falling_speed    = 2;

    dir     = RIGHT;
    moving  = true;
    jumping = false;
    falling = true;
    dying   = false;
    dead    = false;
    freezed = false;

    collectable = false;

    jump_counter    = 0;
    death_counter   = 0;
    walk_counter    = 0;
    freeze_counter	= 0;

    jumping_duration = 30;
    death_duration   = 100;
    freeze_duration  = 80;

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

    if(jumping)
    {
        prevPos = pos();

        setY(y() - jumping_speed);

        jump_counter += jumping_speed;


        if(jump_counter > jumping_duration)
            endJumping();
    }

    if(falling)
    {
        prevPos = pos();

        setY(y() + falling_speed);

    }


    if(y() > Game::instance()->getScene()->sceneRect().height() - 50 && !dying)
        // die();
    {
        falling = false;
        setY(400);
    }

    if(dying)
    {
        death_counter++;
        if(death_counter > death_duration)
            dead = true;
    }
}


void Entity::die()
{
    if(!dying && !dead)
    {

        dying = true;


        death_counter = 0;

        moving = false;
    }
}
