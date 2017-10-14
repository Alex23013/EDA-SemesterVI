#include "cnode.h"

cNode::cNode(int info,int level)
{
    this->info=info;
    this->level=level;
    childs[0] = nullptr;
    childs[1] = nullptr;
    graphics = nullptr;
}
