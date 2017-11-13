#ifndef FATNODES_H
#define FATNODES_H
#include "cbinarytree.h"
#include<QVector>

class cfatNode
{

public:
    QVector <cbinarytree*> versiones;
    cbinarytree* versionActual;

    cfatNode();
    void insertValue(int x);
    void deleteValue(int x); /*TODO: implementar*/
    void changeValue(int x, int newX);

    void addVersion();
    void deleteVersion();
    void changeVersionActual(int newActualVersion);
    void test();
    void contenidoActual();
    void contenidoEnT(int tiempo);

    /*TODO: implementar*/
    void undo(); // volver un cambio hasta el 0
    void redo(); // retroceder un cambio hasta el actual
};

#endif // FATNODES_H
