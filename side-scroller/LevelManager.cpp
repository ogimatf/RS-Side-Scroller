#include <QPen>
#include <QBrush>
#include <QList>
#include <QFile>
#include <QIODevice>
#include <QString>
#include <QTextStream>
#include <QGradient>

#include "Player.h"
#include "LevelManager.h"
#include "Block.h"
#include <iostream>
#include <fstream>
#include <string>

Player* LevelManager::load(std::string level_name, QGraphicsScene * scene)
{
    Player* player = 0;

    if(level_name == "World-1-1")
    {

        scene->setBackgroundBrush(QBrush(QImage(":/images/nebo.jpg")));

        player = new Player(QPoint(350, 350));
        player->setPos(100, 100);

        QFile myfile(":/images/level.txt");

        if(!myfile.open(QIODevice::ReadOnly | QIODevice::Text))
            std::cerr << "File not open";

        QTextStream in(&myfile);

        int block_x_coord = 0;
        int block_y_coord = 0;

        Block* block = new Block();

        float block_dim = block->boundingRect().height();

        delete block;

        QList<Block *> blocks;


        while(!in.atEnd()){

            QString line = in.readLine();

            for(auto c : line){

                //std::cout << c.unicode() << std::endl;

                if(c == '#'){

                    blocks.append(new Block());
                    blocks.last()->setPos(block_x_coord, block_y_coord);

                    //std::cout << "On udarac, ja blok!" << std::endl;

                }

                block_x_coord += block_dim;
            }

            block_y_coord += block_dim;
            block_x_coord = 0;
        }

        myfile.close();

    }
    else
        std::cerr << "Level not implemented";

    return player;
}
