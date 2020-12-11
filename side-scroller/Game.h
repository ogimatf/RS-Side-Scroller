#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>


#include "Player.h"
#include "Levelmanager.h"

class Game : public QGraphicsView
{
    Q_OBJECT

    enum game_state{READY, RUNNING, PAUSE, GAME_OVER};

    private:

        static Game* uniqueInstance;	// Singleton design pattern
        Game(QGraphicsView *parent=0);	// Singleton design pattern

        QGraphicsScene *scene;          // the scene used to render the game (2D)
        Player *player;                   // player object
        QTimer engine;                  // game engine / timer
        game_state cur_state;           // current game state


    protected:

        // the game is controlled using the keyboard
        // hence we have to intercept all keyboard events
        virtual void keyPressEvent(QKeyEvent *e);
        virtual void keyReleaseEvent(QKeyEvent *e);


    public:

        // get unique instance
        static Game* instance();

        // getters
        QGraphicsScene* getScene(){return scene;}

        void displayMainMenu();

    public slots:

        // advance game / next frame
        void advance();

        // pause / resume game
        void tooglePause();

        // reset game
        void reset();

        // start new game
        void start();

        // game over
        void gameover();

};
