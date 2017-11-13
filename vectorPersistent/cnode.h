#ifndef CNODE_H
#define CNODE_H

class cnodeGraphic;

class cNode
{
public:
    int info;
    int level;
    int version;
    cNode* childs[2];

    cnodeGraphic* graphics;

    cNode(int info, int level, int version);
    void eject(bool side);//borrar un side=0 o 1 / left o right
    void inject(cNode* node, bool side); // ingresa un nodo n  en este side
    void changeValue(int newValue); //cambiar el valor del nodo

};

#endif // CNODE_H
