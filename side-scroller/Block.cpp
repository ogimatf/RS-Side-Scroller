#include "Block.h"


Block::Block() : Inert() {
  setShapeMode(QGraphicsPixmapItem::MaskShape);
  setPixmap(QPixmap(":/images/Textures/block_steel_01.png"));
}


