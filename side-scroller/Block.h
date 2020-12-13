#ifndef BLOCK_H
#define BLOCK_H

#include "Inert.h"

class Block : public Inert
{
    public:

        Block();

        virtual std::string name() { return "Block"; }
        virtual void hit(Object *what, Direction fromDir);
};

#endif // BLOCK_H
