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

void cNode::eject(bool side)//borrar un side=0 o 1 / left o right
{
    delete (this->childs[side]);
    this->childs[side] = nullptr;
}

void cNode:: inject(cNode* n, bool side) // ingresa un nodo n  en este side
{
    this->childs[side] = n;
}

void cNode:: change(int e)
{
    this->info = e;
}
