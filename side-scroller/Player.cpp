#include "Player.h"
#include "Game.h"

#include <QPen>
#include <QBrush>

#include <iostream>

Player::Player(QPoint position) : Entity() {
    moving = false;
    running = false;

    x = position.x();
    y = position.y();

    jumping_duration = jump_duration_small;
    death_duration = 300;

    setZValue(3);

    rect = scene()->addRect(0, 0, 50, 50);
}

void Player::jump() {
    if (jumping)
        return;

    startJumping();
}

void Player::animate() {
    std::cout << "Position: " << pos().x() << "," << pos().y() << "      \r";
        rect->setPos(pos().x(), pos().y());
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
