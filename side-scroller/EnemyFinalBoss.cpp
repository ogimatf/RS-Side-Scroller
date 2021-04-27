#include "EnemyFinalBoss.h"
#include "FinalBossBullet1.h"
#include "FinalBossBullet2.h"

#include <iostream>

EnemyFinalBoss::EnemyFinalBoss() : Enemy() {
  health = 20;
  texture_idle[0] = QPixmap(":/images/Textures/finalboss_idle_00.png");
  texture_idle[1] = QPixmap(":/images/Textures/finalboss_idle_01.png");
  texture_shooting_fireball[0] =
    QPixmap(":/images/Textures/finalboss_shoot_00.png");
  texture_shooting_fireball[1] =
    QPixmap(":/images/Textures/finalboss_shoot_01.png");
  texture_shooting_firewave[0] =
    QPixmap(":/images/Textures/finalboss_shoot_02.png");
  texture_shooting_firewave[1] =
    QPixmap(":/images/Textures/finalboss_shoot_03.png");
  texture_dying[0] = QPixmap(":/images/Textures/finalboss_death_00.png");
  texture_dying[1] = QPixmap(":/images/Textures/finalboss_death_01.png");
  texture_dying[2] = QPixmap(":/images/Textures/finalboss_death_02.png");
  texture_dying[3] = QPixmap(":/images/Textures/finalboss_death_03.png");

  setPixmap(texture_idle[0]);
}
void EnemyFinalBoss::damageEnemy(int damage) {
  if (!invulnerable) {
    health -= damage;
    if (health <= 0) {
      dying = true;
      shooting = false;
    }
  }
}

void EnemyFinalBoss::animate() {

  int fire_animation_index = enemy_animation_interval % 100 < 50 ? 0 : 1;

  int wave_animation_index;

  if (enemy_animation_interval % 90 < 45)
    wave_animation_index = 0;
  else
    wave_animation_index = 1;

  if (dying || dead) {
    if (death_counter > 25 && death_counter < 50)
      death_ind = 1;
    else if (death_counter > 50 && death_counter < 75)
      death_ind = 2;
    else if (death_counter > 75)
      death_ind = 3;

    setPixmap(texture_dying[death_ind]);
  } else if (!shooting)
    setPixmap(texture_idle[fire_animation_index]);
  else if (shooting && shooting_style == 1)
    setPixmap(texture_shooting_fireball[fire_animation_index]);
  else if (shooting && shooting_style == 2)
    setPixmap(texture_shooting_firewave[wave_animation_index]);

  /*


 */
}

void EnemyFinalBoss::enemyShoot() {

  if (shooting) {
    fire_counter++;
    shooting_style = fire_counter % 11 < 7 ? 1 : 2;
    if (shooting_style == 1) {
      FinalBossBullet1 *bullet = new FinalBossBullet1(this->getDir());
      //            if(dir == RIGHT){
      //                bullet->setPos(pos().x() + boundingRect().width()/2,
      //                pos().y() + boundingRect().height()/3 + 10);
      //            }

      bullet->setPos(pos().x() - boundingRect().width() / 2,
                     pos().y() + boundingRect().height() / 3 + 10);
    } else {
      FinalBossBullet2 *bullet = new FinalBossBullet2(this->getDir());
      //            if(dir == RIGHT){
      //                bullet->setPos(pos().x() + boundingRect().width() + 15,
      //                pos().y() + boundingRect().height()/3);
      //            }

      bullet->setPos(pos().x() - boundingRect().width(), pos().y() + 10);
    }
  }
}
