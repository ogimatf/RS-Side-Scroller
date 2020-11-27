#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

#ifndef PLAYER_H
#define PLAYER_H


class Player : public QGraphicsPixmapItem{
public:
    Player();
    Player(QGraphicsItem *parent);

    int direction();
    void setDirection(int direction);

private:
    int m_direction;
};

#endif // PLAYER_H
