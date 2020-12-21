#include "EnemySniperJoe.h"
#include "Bullet.h"

EnemySniperJoe::EnemySniperJoe() : Enemy()
{
    health = 10;
    setPixmap(QPixmap(":/images/Textures/sniperjoe_01.png"));
}
void EnemySniperJoe::animate(){

}

void EnemySniperJoe::enemyShoot(){
    if(shooting){
        Bullet* bullet = new Bullet(this->getDir());
        if(dir == RIGHT){
            bullet->setPos(pos().x() + boundingRect().width() + 15, pos().y() + boundingRect().height()/3);
        }
        else {
            bullet->setPos(pos().x() - boundingRect().width() - 15, pos().y() + boundingRect().height()/3);
        }
    }
}
