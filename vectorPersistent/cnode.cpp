#include "cnode.h"

cNode::cNode(int info,int level, int version)
{
    this->info=info;
    this->level=level;
    this->version = version;
    childs[0] = nullptr;
    childs[1] = nullptr;
    graphics = nullptr;
}

void cNode::eject(bool side)
{
    delete (this->childs[side]);
    this->childs[side] = nullptr;
}

void cNode:: inject(cNode* node, bool side)
{
    this->childs[side] = node;

}

void cNode:: changeValue(int newValue)
{
    this->info = newValue;
}

