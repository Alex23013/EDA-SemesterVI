#ifndef CNODE_H
#define CNODE_H
#include "cfatnodes.h"

class cnodeGraphic;

class cfatNode;
class cNode
{
public:
    int info;
    int level;
    int version;
    cfatNode* childs[2];

    cnodeGraphic* graphics;

    cNode(int info, int level, int version);
    void eject(bool side);//borrar un side=0 o 1 / left o right
    void inject(cNode* n, bool side); // ingresa un nodo n  en este side
    void change(int e); //cambiar el valor del nodo
    cNode* getCurrentChild(bool side);
};

#endif // CNODE_H
