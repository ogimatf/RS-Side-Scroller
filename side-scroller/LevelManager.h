#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <QGraphicsScene>
#include <string>

#include "Player.h"

class LevelManager
{
    public:
        static Player* load(std::string level_name, QGraphicsScene * scene);

};

#endif // LEVELMANAGER_H
