#include "EnemyPickman.h"

EnemyPickman::EnemyPickman() : Enemy()
{
    health = 10;
    setPixmap(QPixmap(":/images/pickman_01.png"));
}
void EnemyPickman::animate(){

}
