#include "Game.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  Game::instance()->show();

  return app.exec();
}
