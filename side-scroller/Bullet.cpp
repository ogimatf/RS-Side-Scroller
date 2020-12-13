#include "Bullet.h"

#include <QTimer>
#include <QList>

Bullet::Bullet()
{

    setPixmap(QPixmap(":/images/bullet.png"));
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move_bullet()));
    timer->start(50);
}

void Bullet::move_bullet()
{

//    QList<QGraphicsItem *> colliding_items = collidingItems();
    setPos(x() + 10, y());

}

