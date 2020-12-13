#include <QPen>
#include <QBrush>
#include <QGradient>

#include "Player.h"
#include "LevelManager.h"
#include "Block.h"
#include <iostream>

Player* LevelManager::load(std::string level_name, QGraphicsScene * scene)
{
    Player* player = 0;

    if(level_name == "World-1-1")
    {

        QLinearGradient linearGrad(QPointF(100, 100), QPointF(2000, 400));
        linearGrad.setColorAt(0, Qt::cyan);
        linearGrad.setColorAt(1, Qt::black);

        scene->setBackgroundBrush(QBrush(QImage(":/images/nebo.jpg")));

        player = new Player(QPoint(350, 350));
        player->setPos(0,0);

        Block* block = new Block();
        block->setPos(0,450 - block->boundingRect().height());
    }
    else
        std::cerr << "Level not implemented";

    return player;
}
