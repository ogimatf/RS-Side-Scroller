#include <QPen>
#include <QBrush>
#include <QGradient>

#include "Player.h"
#include "Levelmanager.h"

#include <iostream>


// load all items from the given level in the given scene
Player* LevelManager::load(std::string level_name, QGraphicsScene * scene)
{
    Player* player = 0;

    if(level_name == "World-1-1")
    {
        // terrain level
        int terrain_level = 200;

        // set background color
        QLinearGradient linearGrad(QPointF(100, 100), QPointF(2000, 400));
        linearGrad.setColorAt(0, Qt::cyan);
        linearGrad.setColorAt(1, Qt::black);
//        scene->setBackgroundBrush(QBrush(linearGrad));
        scene->setBackgroundBrush(QBrush(QImage(":/img/nebo.jpg")));

        // Player
        player = new Player(QPoint(350, 350));
    }
    else
        std::cerr << "Level not implemented";

    return player;
}
