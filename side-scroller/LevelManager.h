#pragma once

#include <QGraphicsScene>
#include <string>

#include "Player.h"

class LevelManager
{
    public:

        // load all items from the given level in the given scene
        // returns the Player object
        static Player* load(std::string level_name, QGraphicsScene * scene);
};
