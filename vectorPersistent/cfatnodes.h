#ifndef FATNODES_H
#define FATNODES_H
#include "cbinarytree.h"
#include<QVector>

class cfatNode
{

public:
    QVector <cbinarytree*> versiones;
    cbinarytree* versionActual;
    int cambio;

    cfatNode();
    void insertValue(int x);
    void deleteValue(int x, bool side);
    void changeValue(int x, int newX);

    void addVersion();
    void deleteVersion();
    void test();
    void contenidoActual();
    void contenidoEnT(int tiempo);

    void undo();
    void redo();
    void reset();
};

#endif // FATNODES_H
