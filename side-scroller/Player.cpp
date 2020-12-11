#include "Player.h"
#include "Game.h"

#include <QPen>
#include <QBrush>

#include <iostream>

// Constructor
Player::Player(QPoint position) : Entity() {
    // Set flags
    moving = false;
    running = false;

    // Set position
    x = position.x();
    y = position.y();

    // Actions flow
    jumping_duration = jump_duration_small;
    death_duration = 300;

    setZValue(3);

    // Show player
    rect = scene()->addRect(0, 0, 50, 50);
}

// Method start jumping by jump flag
void Player::jump() {
    if (jumping)
        return;

    startJumping();
}

// Method move player
void Player::animate() {
    std::cout << "Position: " << pos().x() << "," << pos().y() << "      \r";
        rect->setPos(pos().x(), pos().y());
}

// Method moves player from scene when die
void Player::die() {
    Entity::die();
    collidable = false;

    freeze();
    jumping_speed = 1;
    falling_speed = 1;
    startJumping();
}

// Method increase moving speed
void Player::setRunning(bool _running) {
    if (running == _running)
        return;

    running = _running;

    if (running)
        moving_speed *= 2;
    else
        moving_speed /= 2;
}
