#include "Enemy.h"
#include <QPixmap>

#include "Pickaxe.h"
#include "Game.h"
#include "stdlib.h"

Enemy::Enemy(): Entity()
{
    dir = LEFT;
    shooting = true;
    moving = false;
    health = 5;

}
void Enemy::damageEnemy(int damage){
    health -= damage;
    if(health <= 0){
        dead = true;
    }
}

void Enemy::advance(){

    if(!isDead()){

        enemy_shooting_interval++;

        if(enemy_shooting_interval > 100){
            enemy_shooting_interval = 0;
            enemyShoot();
        }
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

