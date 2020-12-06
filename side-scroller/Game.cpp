#include <iostream>
#include <QApplication>
#include <QKeyEvent>
#include <QScrollBar>
#include <QThread>
#include <QGradient>

#include "Game.h"
#include "Object.h"
#include "Entity.h"
#include "Player.h"

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
	setInteractive(false);
	setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
	setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
	scene->setSceneRect(0, 0, 10000, 450);

    // setup game engine
    QObject::connect(&engine, SIGNAL(timeout()), this, SLOT(advance()));
    engine.setInterval(10);


	player = 0;
	reset();

	// setup window size
	this->setFixedHeight(450);
	this->setFixedWidth(800);
}

// reset game
void Game::reset()
{
	QLinearGradient linearGrad(QPointF(100, 100), QPointF(800, 400));
    linearGrad.setColorAt(0, Qt::blue);
    linearGrad.setColorAt(1, Qt::white);

	cur_state = READY;
	player = 0;
	engine.stop();
	scene->clear();
	scene->setBackgroundBrush(QBrush(linearGrad));
	
	// display welcome message
	QGraphicsTextItem* text = scene->addText("Press \"S\" to start a new game");
	text->setPos(300,90);
	centerOn(text);
}

// game over
void Game::gameover()
{
	// stop game
	cur_state = GAME_OVER;
	engine.stop();

	// set black background
	scene->setBackgroundBrush(QBrush(Qt::black));

}

// start new game
void Game::start()
{
	
	if(cur_state == READY)
	{
		scene->clear();
		engine.start();
		player = LevelManager::load("World-1-1", scene);

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

// pause / resume game
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
	// start new game
	if(e->key() == Qt::Key_S && cur_state == READY)
		start();

	// reset game
	if(e->key() == Qt::Key_R || cur_state == GAME_OVER)
		reset();

	// pause game
	if(e->key() == Qt::Key_P){
		std::cout << "Action: Pause           \n\r";
		tooglePause();
	}

	// from now on, all commands require the game to be running
	if(cur_state != RUNNING)
		return;

    // horizontal Player's movements
    if(e->key() == Qt::Key_Right || e->key() == Qt::Key_Left)
    {
        player->setMoving(true);
        player->setDirection(e->key() == Qt::Key_Right ? Direction::RIGHT : Direction::LEFT);
    }

    // Player jump
    if(e->key() == Qt::Key_Space)
	{
		std::cout << "Action: Jump           \n\r";
		
        player->jump();
	}

	// Player's running
	if(e->key() == Qt::Key_Z){

	  	std::cout << "Action: Run            \n\r";
		player->setRunning(true);
	}

}

void Game::keyReleaseEvent(QKeyEvent *e)
{
	// from now on, all commands require the game to be running
	if(cur_state != RUNNING)
		return;

    // horizontal Player's movements
    if(e->key() == Qt::Key_Right || e->key() == Qt::Key_Left)
        player->setMoving(false);

	// Player's running
	if(e->key() == Qt::Key_Z)
		player->setRunning(false);
}

void Game::advance()
{
	// do nothing if game is not running
	if(cur_state != RUNNING)
		return;

	// if player is dead, game over
	if(player->isDead())
	{
		gameover();
	}

	// if player is dying animate/advance only him
	// (the rest of the world is freezed)
	if(player->isDying())
	{	
		player->animate();
		player->advance();
		return;
	}

	// tell all game objects to animate and advance in the scene
    for(auto & item : scene->items())
    {
		Object* obj = dynamic_cast<Object*>(item);
		if(obj)
		{
			obj->animate();
			obj->advance();

			// destroy died Entity objects
			Entity* entity_obj = dynamic_cast<Entity*>(obj);
			if(entity_obj && entity_obj->isDead())
			{
				std::cout << entity_obj->name() << std:: endl;
				scene->removeItem(entity_obj);
				delete entity_obj;
			}
		}
    }

    // center view on Player
    centerOn(player);
}
