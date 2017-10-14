#ifndef CNODE_H
#define CNODE_H


class cnodeGraphic;

class cNode
{
public:
    int info;
    int level;
    cNode* childs[2];

   cnodeGraphic* graphics;

    cNode(int info, int level);
    void eject(bool side);//borrar un side=0 o 1 / left o right
    void inject(cNode* n, bool side); // ingresa un nodo n  en este side
    void change(int e); //cambiar el valor del nodo
};

#endif // CNODE_H
