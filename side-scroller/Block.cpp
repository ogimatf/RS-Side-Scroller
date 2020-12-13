#include "Block.h"


Block::Block() : Inert()
{
    setPixmap(QPixmap(":/images/block.png"));
}

void Block::hit(Object *what, Direction fromDir)
{
}
