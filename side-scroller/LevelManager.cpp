#include <QPen>
#include <QBrush>
#include <QList>
#include <QFile>
#include <QIODevice>
#include <QString>
#include <QTextStream>
#include <QGradient>

#include "Player.h"
#include "Babe.h"
#include "Enemy.h"
#include "EnemyPickman.h"
#include "EnemySniperJoe.h"

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

        //scene->setBackgroundBrush(QBrush(QImage(":/images/nebo.jpg")));
        scene->setBackgroundBrush(QBrush(QColor(31,0,164)));

        player = new Player(QPoint(350, 350));
        player->setPos(100, 100);

        QFile myfile(":/txt/Levels/level.txt");

        if(!myfile.open(QIODevice::ReadOnly | QIODevice::Text))
            std::cerr << "File not open";

        QTextStream in(&myfile);

        int block_x_coord = 0;
        int block_y_coord = 0;

        Block* block = new Block();

        float block_dim = block->boundingRect().height();

        delete block;

        QList<Block *> blocks;
        QList<Enemy *> enemies;

        Babe* princess = new Babe();


        while(!in.atEnd()){

            QString line = in.readLine();

            for(auto c : line){

                if(c == '#')
                {

                    blocks.append(new Block());
                    blocks.last()->setPixmap(QPixmap(":/images/Textures/block_steel_02.png"));
                    blocks.last()->setPos(block_x_coord, block_y_coord);

                }
                else if(c == '1')
                {

                    blocks.append(new Block());
                    blocks.last()->setPixmap(QPixmap(":/images/Textures/block_rock_01.png"));
                    blocks.last()->setPos(block_x_coord, block_y_coord);

                }
                else if(c == '2')
                {

                    blocks.append(new Block());
                    blocks.last()->setPixmap(QPixmap(":/images/Textures/block_rock_02.png"));
                    blocks.last()->setPos(block_x_coord, block_y_coord);

                }
                else if(c == '3')
                {

                    blocks.append(new Block());
                    blocks.last()->setPixmap(QPixmap(":/images/Textures/block_rock_03.png"));
                    blocks.last()->setPos(block_x_coord, block_y_coord);

                }
                else if(c == '4')
                {

                    blocks.append(new Block());
                    blocks.last()->setPixmap(QPixmap(":/images/Textures/block_rock_04.png"));
                    blocks.last()->setPos(block_x_coord, block_y_coord);

                }
                else if(c == 'S')
                {

                    blocks.append(new Block());
                    blocks.last()->setPixmap(QPixmap(":/images/Textures/block_steel_01.png"));
                    blocks.last()->setPos(block_x_coord, block_y_coord);

                }
                else if(c == 'T')
                {

                    blocks.append(new Block());
                    blocks.last()->setPixmap(QPixmap(":/images/Textures/block_steel_02.png"));
                    blocks.last()->setPos(block_x_coord, block_y_coord);

                }
                else if(c == 'E')
                {

                    blocks.append(new Block());
                    blocks.last()->setPixmap(QPixmap(":/images/Textures/block_steel_03.png"));
                    blocks.last()->setPos(block_x_coord, block_y_coord);

                }
                else if(c == 'P')
                {

                    blocks.append(new Block());
                    blocks.last()->setPixmap(QPixmap(":/images/Textures/block_pipe_01.png"));
                    blocks.last()->setPos(block_x_coord, block_y_coord);

                }
                else if(c == 'I')
                {
                    blocks.append(new Block());
                    blocks.last()->setPixmap(QPixmap(":/images/Textures/block_pipe_02.png"));
                    blocks.last()->setPos(block_x_coord, block_y_coord);

                }
                else if(c == 'L')
                {

                    blocks.append(new Block());
                    blocks.last()->setPixmap(QPixmap(":/images/Textures/block_platform.png"));
                    blocks.last()->setPos(block_x_coord, block_y_coord);

                }
                else if(c == 'X')
                {

                    blocks.append(new Block());
                    blocks.last()->setPixmap(QPixmap(":/images/Textures/block_x_01.png"));
                    blocks.last()->setPos(block_x_coord, block_y_coord);

                }
                else if(c == 'Q'){
                    enemies.append(new EnemyPickman());
                    enemies.last()->setPos(block_x_coord, block_y_coord - enemies.last()->boundingRect().height());
                }
                else if(c == 'R'){
                    enemies.append(new EnemySniperJoe());
                    enemies.last()->setPos(block_x_coord, block_y_coord - enemies.last()->boundingRect().height());
                }
                else if(c == 'B'){
                    princess->setPos(block_x_coord, block_y_coord - enemies.last()->boundingRect().height());
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
