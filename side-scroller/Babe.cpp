#include "Babe.h"
#include "Game.h"

Babe::Babe(): Entity()
{
    dir = LEFT;
    moving = false;
    health = 1;
    player_close = false;


    setPixmap(QPixmap(":/images/Textures/sniperjoe_01.png"));
}

void Babe::damageBabe(int damage){
    health -= damage;
    if(health <= 0){
        dead = true;
    }
}

void Babe::animate(){

}

void Babe::advance(){

    lookForPlayer();

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

        solveCollisions();

    }

    if(jumping)
    {
        prevPos = pos();

        setY(y() - jumping_speed);

        jump_counter += jumping_speed;


        if(jump_counter > jumping_duration)
            endJumping();

        solveCollisions();
    }

    if(walkable_object && !touchingDirection(walkable_object))
            falling = true;

    if(falling)
    {
        prevPos = pos();

        setY(y() + falling_speed);

        solveCollisions();
    }


    if(dying)
    {
        death_counter++;
        if(death_counter > death_duration)
            dead = true;
    }
}

void Babe::lookForPlayer(){
    if(Game::instance()->getPlayer()->pos().x() > this->x()){
        dir = RIGHT;
    }
    else{
        dir = LEFT;
    }
    if(abs(Game::instance()->getPlayer()->pos().x() - this->x()) < 400 && abs(Game::instance()->getPlayer()->pos().y() - this->y()) < 400){
        player_close =  true;
    }
    else {
        player_close = false;
    }
}
