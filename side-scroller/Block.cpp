#include "Block.h"


Block::Block() : Inert()
{
    setShapeMode(QGraphicsPixmapItem::MaskShape);
    setPixmap(QPixmap(":/images/Textures/block_steel_02.png"));
}

void Block::hit(Object *what, Direction fromDir)
{
}
