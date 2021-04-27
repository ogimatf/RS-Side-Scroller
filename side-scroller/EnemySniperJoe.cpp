#include "EnemySniperJoe.h"
#include "SniperJoeBullet.h"

#include <iostream>

EnemySniperJoe::EnemySniperJoe() : Enemy() {
  health = 3;
  texture_idle = QPixmap(":/images/Textures/sniperjoe_01.png");
  texture_shooting[0] = QPixmap(":/images/Textures/sniperjoe_02.png");
  texture_shooting[1] = QPixmap(":/images/Textures/sniperjoe_03.png");
  texture_dying[0] = QPixmap(":/images/Textures/sniperjoe_death_01.png");
  texture_dying[1] = QPixmap(":/images/Textures/sniperjoe_death_02.png");
  texture_dying[2] = QPixmap(":/images/Textures/sniperjoe_death_03.png");
  texture_dying[3] = QPixmap(":/images/Textures/sniperjoe_death_04.png");

  setPixmap(texture_idle);
}
void EnemySniperJoe::animate() {

  if (dying || dead) {
    if (death_counter > 25 && death_counter < 50)
      death_ind = 1;
    else if (death_counter > 50 && death_counter < 75)
      death_ind = 2;
    else if (death_counter > 75)
      death_ind = 3;

    setPixmap(texture_dying[death_ind]);
  } else if (enemy_shooting_interval < 50) {
    setPixmap(texture_idle);
  } else if (enemy_shooting_interval > 50 && enemy_shooting_interval < 80) {
    setPixmap(texture_shooting[0]);
  } else {
    setPixmap(texture_shooting[1]);
  }
  if (dir == RIGHT) {
    setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
  }
}

void EnemySniperJoe::enemyShoot() {
  if (shooting) {
    SniperJoeBullet *bullet = new SniperJoeBullet(this->getDir());
    if (dir == RIGHT) {
      bullet->setPos(pos().x() + boundingRect().width(),
                     pos().y() + boundingRect().height() / 3);
    } else {
      bullet->setPos(pos().x() - boundingRect().width(),
                     pos().y() + boundingRect().height() / 3);
    }
  }
}
