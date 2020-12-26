#include "Enemy.h"
#include <QPixmap>
#include <QSound>

#include "Pickaxe.h"
#include "Game.h"
#include "stdlib.h"

Enemy::Enemy(): Entity()
{
    dir = LEFT;
    shooting = true;
    moving = false;
    health = 5;
    player_close = false;
}
void Enemy::damageEnemy(int damage){

    QSound::play(":/audio/Sounds/EnemyDamage.wav");

    health -= damage;

    if(health <= 0){
        dying = true;
        shooting = false;
    }
}

void Enemy::advance(){

    lookForPlayer();

    if(!isDead()){

        enemy_shooting_interval++;

        if(enemy_shooting_interval > 100 && player_close){
            enemy_shooting_interval = 0;

            QSound::play(":/audio/Sounds/EnemyShoot.wav");
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
        death_counter += 5;
        if(death_counter > death_duration)
            dead = true;
    }
}

void Enemy::lookForPlayer(){
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
        enemy_shooting_interval = 0;
        player_close = false;
    }
}
