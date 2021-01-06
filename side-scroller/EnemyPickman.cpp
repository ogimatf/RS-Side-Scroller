#include "EnemyPickman.h"
#include "Pickaxe.h"

EnemyPickman::EnemyPickman() : Enemy()
{
    health = 4;
    texture_idle        = QPixmap(":/images/Textures/pickman_01.png");
    texture_shooting[0] = QPixmap(":/images/Textures/pickman_02.png");
    texture_shooting[1] = QPixmap(":/images/Textures/pickman_03.png");
    texture_dying[0]    = QPixmap(":/images/Textures/pickman_death_01.png");
    texture_dying[1]    = QPixmap(":/images/Textures/pickman_death_02.png");
    texture_dying[2]    = QPixmap(":/images/Textures/pickman_death_03.png");
    texture_dying[3]    = QPixmap(":/images/Textures/pickman_death_04.png");


    setPixmap(texture_idle);
}
void EnemyPickman::animate(){

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

void EnemyPickman::enemyShoot(){
    if(shooting){
        Pickaxe* pickaxe = new Pickaxe(this->getDir());
        if(dir == RIGHT){
            // + 5 da sekira ne udara u Pickman-a
            pickaxe->setPos(pos().x() + boundingRect().width() + 5, pos().y() + boundingRect().height()/3);
        }
        else {
            pickaxe->setPos(pos().x() - boundingRect().width(), pos().y() + boundingRect().height()/3);
        }
    }
}
