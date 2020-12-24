#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>


#include "Player.h"
#include "LevelManager.h"
#include "HealthBar.h"

class Game : public QGraphicsView
{
    Q_OBJECT

    enum game_state{READY, RUNNING, PAUSE, GAME_OVER};

    private:

        static Game* uniqueInstance;
        Game(QGraphicsView *parent=0);

        QGraphicsScene *scene;
        HealthBar* health_bar;
        Player *player;
        QTimer engine;
        game_state cur_state;


    protected:

        virtual void keyPressEvent(QKeyEvent *e);
        virtual void keyReleaseEvent(QKeyEvent *e);


    public:

        static Game* instance();

        QGraphicsScene* getScene(){return scene;}
        Player* getPlayer(){return player;}




    public slots:


        void advance();


        void tooglePause();


        void reset();


        void start();

        void gameover();

        void displayOptions();

        void displayMainMenu();

};

#endif // GAME_H
