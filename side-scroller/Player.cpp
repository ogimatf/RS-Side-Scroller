#include "Player.h"
#include "Game.h"

#include <QPen>
#include <QBrush>
#include <QPixmap>
#include <iostream>

Player::Player(QPoint position) : Entity() {
    moving = false;
    running = false;

    x = position.x();
    y = position.y();

    jumping_duration = jump_duration;
    death_duration = 300;

    setZValue(3);

    texture_stand   = QPixmap(":/images/megaman_idle.png");
    texture_jump    = QPixmap(":/images/megaman_jump.png");
    texture_walk[0] = QPixmap(":/images/megaman_run_01.png");
    texture_walk[1] = QPixmap(":/images/megaman_run_02.png");
    texture_walk[2] = QPixmap(":/images/megaman_run_03.png");

    setPixmap(texture_stand);
}

void Player::jump() {
    if (jumping)
        return;

    startJumping();
}

void Player::animate() {

    if(moving && !jumping && !falling)
    {
        setPixmap(texture_walk[(walk_counter++/(running ? running_div : walk_div))%3]);
    }
    else if(jumping || falling)
    {
            setPixmap(texture_jump);
    }
    else
    {
        setPixmap(texture_stand);
    }


    if(dir == LEFT)
    {
        setPixmap(pixmap().transformed(QTransform().scale(-1,1)));
    }
}


void Player::die() {

    Entity::die();
    collidable = false;

    freeze();
    jumping_speed = 1;
    falling_speed = 1;
    startJumping();
}

void Player::setRunning(bool _running) {
    if (running == _running)
        return;

    running = _running;

    if (running)
        moving_speed *= 2;
    else
        moving_speed /= 2;
}
