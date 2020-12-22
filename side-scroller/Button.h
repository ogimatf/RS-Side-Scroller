#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <string>

class Button:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Button(std::string type,int posx, int posy);
    std::string name1,name2;
    QPixmap texture[2];

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};

#endif // BUTTON_H
