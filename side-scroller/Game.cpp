#include <QApplication>
#include <QKeyEvent>
#include <QScrollBar>
#include <QThread>
#include <QGradient>
#include <QImage>
#include <QBrush>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

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

    main_menu_music = new QSound(":/audio/Sounds/MegamanMainMenu.wav");
    game_music      = new QSound(":/audio/Sounds/MegamanLevel1.wav");
    victory_music   = new QSound(":/audio/Sounds/MegamanVictory.wav");

    main_menu_music->setLoops(-1);
    game_music->setLoops(-1);


    player = 0;
    reset();

    // setup window size
    this->setFixedWidth(1024);
    this->setFixedHeight(576);

    pause_screen = new QGraphicsPixmapItem();
    pause_screen->setPixmap(QPixmap(":/images/Textures/pause_01.png"));

    death_screen = new QGraphicsPixmapItem();


}

void Game::displayOptions()
{
    scene->clear();
    scene->setBackgroundBrush(QBrush(QImage(":/images/Textures/options.png")));


    back_button = new Button("back", 10, 530);
    connect(back_button, SIGNAL(clicked()), this, SLOT(displayMainMenu()));
    scene->addItem(back_button);


}


void Game::displayMainMenu()
{

    scene->clear();
    scene->setBackgroundBrush(QBrush(QImage(":/images/Textures/pozadinica.png")));

    start_button = new Button("start",445,310);
    connect(start_button, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(start_button);

    options_button = new Button("options",414,340);
    connect(options_button, SIGNAL(clicked()), this, SLOT(displayOptions()));
    scene->addItem(options_button);

    quit_button = new Button("quit",445,375);
    connect(quit_button, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quit_button);

}

void Game::reset()
{

    cur_state = READY;
    player = 0;
    engine.stop();
    scene->clear();
    centerOn(0,0);
    game_music->stop();

    // main menu music
    main_menu_music->play();

    displayMainMenu();

}


void Game::gameover()
{
    cur_state = GAME_OVER;
    engine.stop();

    death_screen->setPixmap(QPixmap(":/images/Textures/you_died_screen.png"));

    if(screen_used)
    {
        scene->removeItem(death_screen);
        screen_used = false;
    }

    scene->addItem(death_screen);
    death_screen->setPos(mapToScene(0,0));
    death_screen->setZValue(4);


    QPointF mm_button_position = mapToScene(390,258);
    main_menu_button = new Button("main_menu",mm_button_position.x(),mm_button_position.y());
    connect(main_menu_button, SIGNAL(clicked()), this, SLOT(reset()));
    main_menu_button->setZValue(5);
    scene->addItem(main_menu_button);


    mm_button_position = mapToScene(460,320);
    quit_button_2 = new Button("qquit",mm_button_position.x(),mm_button_position.y());
    connect(quit_button_2, SIGNAL(clicked()), this, SLOT(close()));
    quit_button_2->setZValue(5);
    scene->addItem(quit_button_2);


    screen_used=true;


}

void Game::start()
{

    if(cur_state == READY)
    {
        scene->clear();
        engine.start();
        player = LevelManager::load("World-1-1", scene);
        QSound::play(":/audio/Sounds/GameStart.wav");

        main_menu_music->stop();
        game_music->play();

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
        scene->addItem(pause_screen);
        pause_screen->setPos(mapToScene(0,0));
        pause_screen->setZValue(5);

        engine.stop();
        cur_state = PAUSE;
    }
    else if(cur_state == PAUSE)
    {
        scene->removeItem(pause_screen);

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

    if(e->key() == Qt::Key_U)
    {
        int direction = player->getDir() == RIGHT ? 1 : -1;
        player->setPos(player->pos().x() + 10*direction,player->pos().y() - 20);
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

    if(player->won)
    {
        game_music->stop();
        victory_music->play();

        QGraphicsPixmapItem *final_screen = new QGraphicsPixmapItem();
        final_screen->setPixmap(QPixmap(":/images/Textures/win_screen.png"));
        scene->addItem(final_screen);
        final_screen->setPos(mapToScene(0,0));
        final_screen->setZValue(4);
        engine.stop();

    }


    if(player->isDead())
    {
        gameover();
        return;
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
