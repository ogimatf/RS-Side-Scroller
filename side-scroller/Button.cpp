#include "Button.h"
#include "Game.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QSound>
#include <string>
#include <iostream>

Button::Button(std::string type, int posx, int posy): QGraphicsPixmapItem(0){

    setShapeMode(QGraphicsPixmapItem::BoundingRectShape);

    name1 = ":/images/Textures/" + type + "_white.png";
    name2 = ":/images/Textures/" + type + "_yellow.png";

    QString name1_q = QString::fromStdString(name1);
    QString name2_q = QString::fromStdString(name2);

    texture[0] = QPixmap(name1_q);
    texture[1] = QPixmap(name2_q);

    setPos(posx,posy);
    setPixmap(texture[0]);



    // allow responding to hover events
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QSound::play(":/audio/Sounds/MenuSelect.wav");
    emit clicked();

}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    setPixmap(texture[1]);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    setPixmap(texture[0]);

}
