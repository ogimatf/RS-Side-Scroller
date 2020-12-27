#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>


#include "Player.h"
#include "LevelManager.h"
#include "HealthBar.h"
#include "Button.h"

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

        QGraphicsPixmapItem *pause_screen;
        QGraphicsPixmapItem *death_screen;

        Button *start_button;
        Button *quit_button;
        Button *options_button;
        Button *back_button;
        Button *main_menu_button;
        Button *quit_button_2;

        bool screen_used = false;


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
