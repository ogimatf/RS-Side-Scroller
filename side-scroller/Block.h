#ifndef BLOCK_H
#define BLOCK_H

#include "Inert.h"

class Block : public Inert
{

    public:

        Block();

        virtual std::string name() { return "Block"; }

        bool is_leathal();
        void set_leathal();
};

#endif // BLOCK_H
