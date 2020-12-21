#include "EnemySniperJoe.h"
#include "SniperJoeBullet.h"

EnemySniperJoe::EnemySniperJoe() : Enemy()
{
    health = 10;
    texture_idle        = QPixmap(":/images/Textures/sniperjoe_01.png");
    texture_shooting[0] = QPixmap(":/images/Textures/sniperjoe_02.png");
    texture_shooting[1] = QPixmap(":/images/Textures/sniperjoe_03.png");

    setPixmap(texture_idle);
}
void EnemySniperJoe::animate(){

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

void EnemySniperJoe::enemyShoot(){
    if(shooting){
        SniperJoeBullet* bullet = new SniperJoeBullet(this->getDir());
        if(dir == RIGHT){
            bullet->setPos(pos().x() + boundingRect().width(), pos().y() + boundingRect().height()/3);
        }
        else {
            bullet->setPos(pos().x() - boundingRect().width(), pos().y() + boundingRect().height()/3);
        }
    }
}
