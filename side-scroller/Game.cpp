#include <QApplication>
#include <QKeyEvent>
#include <QScrollBar>
#include <QThread>
#include <QGradient>
#include <QImage>
#include <QBrush>
#include <QSound>

#include "Game.h"
#include "Object.h"
#include "Entity.h"
#include "Player.h"
#include "Button.h"

#include "Bullet.h"
#include "Rocket.h"
#include <iostream>

// Singleton design pattern
Game* Game::uniqueInstance = 0;
Game* Game::instance()
{
    if(uniqueInstance == 0)
        uniqueInstance = new Game();
    return uniqueInstance;
}


Game::Game(QGraphicsView *parent) : QGraphicsView(parent)
{
   // setup scene/view
    scene = new QGraphicsScene();
    setScene(scene);
    centerOn(0,0);
    setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    scene->setSceneRect(0, 0, 10000, 5608);

    // setup game engine
    QObject::connect(&engine, SIGNAL(timeout()), this, SLOT(advance()));
    engine.setInterval(10);


    player = 0;
    reset();

    // setup window size
    this->setFixedWidth(1024);
    this->setFixedHeight(576);


}

void Game::displayOptions()
{
    scene->clear();
    scene->setBackgroundBrush(QBrush(QImage(":/images/Textures/options.png")));


    Button* backButton = new Button("back", 10, 530);
    connect(backButton, SIGNAL(clicked()), this, SLOT(displayMainMenu()));
    scene->addItem(backButton);


}


void Game::displayMainMenu()
{

    scene->clear();
    scene->setBackgroundBrush(QBrush(QImage(":/images/Textures/pozadinica.png")));

    Button* playButton = new Button("start",445,310);
    connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playButton);

    Button* optionsButton = new Button("options",414,340);
    connect(optionsButton, SIGNAL(clicked()), this, SLOT(displayOptions()));
    scene->addItem(optionsButton);

    Button* quitButton = new Button("quit",445,375);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);

}

void Game::reset()
{

    cur_state = READY;
    player = 0;
    engine.stop();
    scene->clear();
    centerOn(0,0);
    displayMainMenu();

}


void Game::gameover()
{
    cur_state = GAME_OVER;
    engine.stop();


}

void Game::start()
{

    if(cur_state == READY)
    {
        scene->clear();
        engine.start();
        player = LevelManager::load("World-1-1", scene);
        QSound::play(":/audio/Sounds/GameStart.wav");

        health_bar = new HealthBar();


        if(!player)
        {
            scene->setBackgroundBrush(QBrush(Qt::red));
            QGraphicsTextItem* text = scene->addText("Error when loading level");
            text->setPos(300,90);
            centerOn(text);
        }

        cur_state = RUNNING;
    }
}

void Game::tooglePause()
{
    if(cur_state == RUNNING)
    {
        engine.stop();
        cur_state = PAUSE;
    }
    else if(cur_state == PAUSE)
    {
        engine.start();
        cur_state = RUNNING;
    }
}


void Game::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_S && cur_state == READY)
    {
        start();
    }

    if(e->key() == Qt::Key_R || cur_state == GAME_OVER)
    {
        reset();
    }

    if(e->key() == Qt::Key_P)
    {
        QSound::play(":audio/Sounds/Pause.wav");

        tooglePause();
    }

    if(e->key() == Qt::Key_Q)
    {

        if(player->bullet_interval > 20){

            QSound::play(":/audio/Sounds/MegaShoot.wav");

            player->bullet_interval = 0;
            Bullet* bullet = new Bullet(player->getDir());
            if(player->getDir() == RIGHT){
                bullet->setPos(player->pos().x() + player->boundingRect().width() + 15, player->pos().y() + player->boundingRect().height()/3);
            }
            else {
                bullet->setPos(player->pos().x() - bullet->boundingRect().width() - 15, player->pos().y() + player->boundingRect().height()/3);
            }
            player->setShooting(true);
        }
    }

    if(e->key() == Qt::Key_W)
    {
        if(player->rocket_interval > 60){

            QSound::play(":/audio/Sounds/MegamanRocket.wav");

            player->rocket_interval = 0;
            Rocket* rocket = new Rocket(player->getDir());
            if(player->getDir() == RIGHT){
                rocket->setPos(player->pos().x() + player->boundingRect().width() + 15, player->pos().y() + player->boundingRect().height()/3);
            }
            else {
                rocket->setPos(player->pos().x() - rocket->boundingRect().width() - 15, player->pos().y() + player->boundingRect().height()/3);
            }

            player->setShooting(true);
        }
    }

    if(e->key() == Qt::Key_Escape)
    {
        close();
    }

    if(cur_state != RUNNING)
        return;

    if(e->key() == Qt::Key_Right || e->key() == Qt::Key_Left)
    {
        player->setMoving(true);
        player->setDirection(e->key() == Qt::Key_Right ? Direction::RIGHT : Direction::LEFT);
    }

    if(e->key() == Qt::Key_Space)
    {
        player->jump();
    }

    if(e->key() == Qt::Key_Shift){

        player->setRunning(true);
    }

    if(e->key() == Qt::Key_D){
        QSound::play(":/audio/Sounds/MegamanDie.wav");
        player->die();
    }

}

void Game::keyReleaseEvent(QKeyEvent *e)
{
    if(cur_state != RUNNING)
        return;

    if(e->key() == Qt::Key_Right || e->key() == Qt::Key_Left)
        player->setMoving(false);

    if(e->key() == Qt::Key_Shift)
        player->setRunning(false);

    if(e->key() == Qt::Key_Q)
    {
        player->setShooting(false);
    }

    if(e->key() == Qt::Key_W)
    {
        player->setShooting(false);
    }
}

void Game::advance()
{

    if(cur_state != RUNNING)
        return;



    if(player->isDead())
    {
        gameover();
    }

    if(player->isDying())
    {
        player->animate();
        player->advance();
        return;
    }

    player->bullet_interval++;
    player->rocket_interval++;

    for(auto & item : scene->items())
    {
        Object* obj = dynamic_cast<Object*>(item);
            if(obj)
            {
                Projectile* projectile_obj = dynamic_cast<Projectile*>(obj);
                if(projectile_obj){
                    projectile_obj->animate();
                    projectile_obj->advance();
                    continue;
                }

                obj->animate();
                obj->advance();

                Entity* entity_obj = dynamic_cast<Entity*>(obj);

                if(entity_obj && entity_obj->isDead()){
                    scene->removeItem(entity_obj);
                    delete entity_obj;
                }
            }
    }

    centerOn(player);

    health_bar->setPos(mapToScene(30,10));
}
