#include "EnemyFinalBoss.h"
#include "FinalBossBullet1.h"
#include "FinalBossBullet2.h"

#include <iostream>

EnemyFinalBoss::EnemyFinalBoss() : Enemy()
{
    health = 20;
    texture_idle           = QPixmap(":/images/Textures/sniperjoe_01.png");
    texture_shooting[0]    = QPixmap(":/images/Textures/sniperjoe_02.png");
    texture_shooting[1]    = QPixmap(":/images/Textures/sniperjoe_03.png");
    texture_dying[0]       = QPixmap(":/images/Textures/sniperjoe_death_01.png");
    texture_dying[1]       = QPixmap(":/images/Textures/sniperjoe_death_02.png");
    texture_dying[2]       = QPixmap(":/images/Textures/sniperjoe_death_03.png");
    texture_dying[3]       = QPixmap(":/images/Textures/sniperjoe_death_04.png");

    setPixmap(texture_idle);
}
void EnemyFinalBoss::damageEnemy(int damage){
    if (!invulnerable){
        health -= damage;
        if(health <= 0){
            dying = true;
            shooting = false;
        }
    }
}

void EnemyFinalBoss::animate(){

    if(dying || dead)
    {
        if(death_counter > 25 && death_counter < 50)
            death_ind = 1;
        else if(death_counter > 50 && death_counter < 75)
            death_ind = 2;
        else if(death_counter > 75)
            death_ind = 3;

        setPixmap(texture_dying[death_ind]);
    }
    else if(enemy_shooting_interval < 50)
    {
        setPixmap(texture_idle);
    }
    else if(enemy_shooting_interval > 50 && enemy_shooting_interval < 80)
    {
        setPixmap(texture_shooting[0]);
    }
    else
    {
        setPixmap(texture_shooting[1]);
    }
    if(dir == RIGHT){
        setPixmap(pixmap().transformed(QTransform().scale(-1,1)));
    }
}

void EnemyFinalBoss::enemyShoot(){
    if(shooting){
        fire_counter++;
        if(fire_counter % 3 != 0){
            FinalBossBullet1* bullet = new FinalBossBullet1(this->getDir());
            if(dir == RIGHT){
                bullet->setPos(pos().x() + boundingRect().width(), pos().y() + boundingRect().height()/3);
            }
            else {
                bullet->setPos(pos().x() - boundingRect().width(), pos().y() + boundingRect().height()/3);
            }
        }else {
            FinalBossBullet2* bullet = new FinalBossBullet2(this->getDir());
            if(dir == RIGHT){
                bullet->setPos(pos().x() + boundingRect().width() + 15, pos().y() + boundingRect().height()/3);
            }
            else {
                bullet->setPos(pos().x() - boundingRect().width(), pos().y() + boundingRect().height()/3);
            }
        }
    }
}
