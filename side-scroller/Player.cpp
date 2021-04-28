#include "Player.h"
#include "Game.h"

#include <QBrush>
#include <QPen>
#include <QPixmap>
//#include <QSound>
#include <iostream>

Player::Player(QPoint position) : Entity() {

  moving = false;
  running = false;
  health = 10;
  bullet_interval = 0;
  rocket_interval = 0;
  x = position.x();
  y = position.y();

  jumping_duration = jump_duration;
  death_duration = 100;

  setZValue(3);

  texture_stand = QPixmap(":/images/Textures/megaman_idle.png");
  texture_jump[0] = QPixmap(":/images/Textures/megaman_jump.png");
  texture_jump[1] = QPixmap(":/images/Textures/megaman_fall.png");
  texture_walk[0] = QPixmap(":/images/Textures/megaman_run_01.png");
  texture_walk[1] = QPixmap(":/images/Textures/megaman_run_02.png");
  texture_walk[2] = QPixmap(":/images/Textures/megaman_run_03.png");
  texture_stand_shoot = QPixmap(":/images/Textures/megaman_idle_shoot.png");
  texture_jump_shoot[0] = QPixmap(":/images/Textures/megaman_jumpshoot.png");
  texture_jump_shoot[1] = QPixmap(":/images/Textures/megaman_fallshoot.png");
  texture_walk_shoot[0] = QPixmap(":/images/Textures/megaman_runshoot_01.png");
  texture_walk_shoot[1] = QPixmap(":/images/Textures/megaman_runshoot_02.png");
  texture_walk_shoot[2] = QPixmap(":/images/Textures/megaman_runshoot_03.png");
  texture_dying[0] = QPixmap(":/images/Textures/megaman_death_01.png");
  texture_dying[1] = QPixmap(":/images/Textures/megaman_death_02.png");
  texture_dying[2] = QPixmap(":/images/Textures/megaman_death_03.png");
  texture_dying[3] = QPixmap(":/images/Textures/megaman_death_04.png");


  setPixmap(texture_stand);
}

void Player::jump() {

  if (jumping)
    return;

  startJumping();
}

void Player::animate() {

  if (dying || dead) {
    if (death_counter > 25 && death_counter < 50)
      death_ind = 1;
    else if (death_counter > 50 && death_counter < 75)
      death_ind = 2;
    else if (death_counter > 75)
      death_ind = 3;
    setPixmap(texture_dying[death_ind]);
  } else if (moving && !jumping && !falling && !shooting) {
    setPixmap(
      texture_walk[(walk_counter++ / (running ? running_div : walk_div)) % 3]);
  } else if (moving && !jumping && !falling && shooting) {
    setPixmap(
      texture_walk_shoot[(walk_counter++ / (running ? running_div : walk_div)) %
                         3]);
  } else if (jumping && !shooting) {
    setPixmap(texture_jump[1]);
  } else if (falling && !shooting) {
    setPixmap(texture_jump[0]);
  } else if (jumping && shooting) {
    setPixmap(texture_jump_shoot[0]);
  } else if (falling && shooting) {
    setPixmap(texture_jump_shoot[1]);
  } else if (shooting) {
    setPixmap(texture_stand_shoot);
  } else {
    setPixmap(texture_stand);
  }


  if (dir == LEFT) {
    setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
  }
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
void Player::damagePlayer(int damage) {

  //    QSound::play(":/audio/Sounds/MegamanDamage.wav");

  health -= damage;

  if (health <= 0) {
    //        QSound::play(":/audio/Sounds/MegamanDie.wav");
    die();
  }
}
