#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include "player.h"

/*
Ovde implementiramo igraca
kretanje, levo, desno, skakanje...
*/

Player::Player(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
    , m_direction(0)
{
    QPixmap pixmap(":/images/megaman_idle_01.png");
    setPixmap(pixmap);
    setOffset(-pixmap.width() / 2, -pixmap.height() / 2);
}

//vraca smer kretanja
int Player::direction() {
    return m_direction;
}

//postavlja smer kretanja
void Player::setDirection(int direction){
    m_direction = direction;

    if (m_direction != 0) {
        QTransform transform;

        if (m_direction < 0) {
            transform.scale(-1, 1);
        }

        setTransform(transform);
    }
}
