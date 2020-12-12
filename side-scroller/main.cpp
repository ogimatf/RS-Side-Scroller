#include <QApplication>
#include "Game.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Game::instance()->show();

    return app.exec();
}
