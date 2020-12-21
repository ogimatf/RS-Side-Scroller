#include "EnemyPickman.h"
#include "Pickaxe.h"

EnemyPickman::EnemyPickman() : Enemy()
{
    health = 10;
    texture_idle        = QPixmap(":/images/Textures/pickman_01.png");
    texture_shooting[0] = QPixmap(":/images/Textures/pickman_02.png");
    texture_shooting[1] = QPixmap(":/images/Textures/pickman_03.png");


    setPixmap(texture_idle);
}
void EnemyPickman::animate(){

    if(enemy_shooting_interval < 50)
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

}

void EnemyPickman::enemyShoot(){
    if(shooting){
        Pickaxe* pickaxe = new Pickaxe(this->getDir());
        if(dir == RIGHT){
            pickaxe->setPos(pos().x() + boundingRect().width(), pos().y() + boundingRect().height()/3);
        }
        else {
            pickaxe->setPos(pos().x() - boundingRect().width(), pos().y() + boundingRect().height()/3);
        }
    }
}
