#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include "Object.h"
#include <QGraphicsPixmapItem>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();


public slots:
    void move_bullet();

};

#endif // BULLET_H
