#include "cnode.h"

cNode::cNode(int info,int level)
{
    this->info=info;
    this->level=level;
    hijos[0] = nullptr;
    hijos[1] = nullptr;
    graphics = nullptr;
}
