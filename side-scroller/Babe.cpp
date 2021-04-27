#include "Babe.h"
#include "Game.h"

Babe::Babe(): Entity()
{
    dir = LEFT;
    moving = false;
    health = 1;
    player_close = false;

    texture_dying[0]       = QPixmap(":/images/Textures/babe_death_01.png");
    texture_dying[1]       = QPixmap(":/images/Textures/babe_death_02.png");
    texture_dying[2]       = QPixmap(":/images/Textures/babe_death_03.png");
    texture_dying[3]       = QPixmap(":/images/Textures/babe_death_04.png");



}

void Babe::damageBabe(int damage){
    health -= damage;
    if(health <= 0){
        dying = true;
    }
}

void Babe::animate(){

    setPixmap(QPixmap(":/images/Textures/babe.png"));

    if(dying || dead)
    {
        if(death_counter > 25 && death_counter < 50)
        {
            death_ind = 1;            
        }
        else if(death_counter > 50 && death_counter < 75)
        {
            death_ind = 2;
        }
        else if(death_counter > 75)
        {
            death_ind = 3;
        }

        setPixmap(texture_dying[death_ind]);
    }
    if(player_close)
    {
        Game::instance()->getPlayer()->won = true;

    }

    if(dir == RIGHT)
    {
        setPixmap(pixmap().transformed(QTransform().scale(-1,1)));
    }

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
        death_counter += 3;
        if(death_counter > death_duration)
        {
            dead = true;
        }
    }
}

void Babe::lookForPlayer(){
    if(Game::instance()->getPlayer()->pos().x() > this->x()){
        dir = RIGHT;
    }
    else{
        dir = LEFT;
    }
    if(abs(Game::instance()->getPlayer()->pos().x() - this->x()) < 50 && abs(Game::instance()->getPlayer()->pos().y() - this->y()) < 50){
        player_close =  true;
    }
    else {
        player_close = false;
    }
}
