#include "Enemy.h"
#include <QPixmap>

#include "Bullet.h"

Enemy::Enemy(): Entity()
{
    dir = LEFT;
    shooting = true;
    moving = false;
    health = 5;
    damage = 1;
}
void Enemy::damageEnemy(int damage){
    health -= damage;
    if(health <= 0){
        dead = true;
    }
}

void Enemy::enemyShoot(){
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
