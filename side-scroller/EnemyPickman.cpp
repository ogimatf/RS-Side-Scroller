#include "EnemyPickman.h"

EnemyPickman::EnemyPickman() : Enemy()
{
    health = 10;
    setPixmap(QPixmap(":/images/Textures/pickman_01.png"));
}
void EnemyPickman::animate(){

}
