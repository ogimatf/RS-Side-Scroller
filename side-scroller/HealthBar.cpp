#include "HealthBar.h"
#include "Game.h"


HealthBar::HealthBar() : Object()
{
    texture_health_bar[10] = QPixmap(":/images/Textures/health_bar_10.png");
    texture_health_bar[9] = QPixmap(":/images/Textures/health_bar_09.png");
    texture_health_bar[8] = QPixmap(":/images/Textures/health_bar_08.png");
    texture_health_bar[7] = QPixmap(":/images/Textures/health_bar_07.png");
    texture_health_bar[6] = QPixmap(":/images/Textures/health_bar_06.png");
    texture_health_bar[5] = QPixmap(":/images/Textures/health_bar_05.png");
    texture_health_bar[4] = QPixmap(":/images/Textures/health_bar_04.png");
    texture_health_bar[3] = QPixmap(":/images/Textures/health_bar_03.png");
    texture_health_bar[2] = QPixmap(":/images/Textures/health_bar_02.png");
    texture_health_bar[1] = QPixmap(":/images/Textures/health_bar_01.png");
    texture_health_bar[0] = QPixmap(":/images/Textures/health_bar_00.png");


    setPixmap(texture_health_bar[10]);

}

void HealthBar::advance()
{}

void HealthBar::animate()
{
    setPixmap(texture_health_bar[Game::instance()->getPlayer()->health]);
}

void HealthBar::solveCollisions()
{}

