#ifndef FATNODES_H
#define FATNODES_H
#include"cnode.h"
#include<QVector>

class cNode;
class cfatNode
{

public:
    QVector <cNode*> versiones;
    cNode* versionActual;

    cfatNode();
    void addVersion();
    void deleteVersion();
    void changeVersionActual(int newActualVersion);
};

#endif // FATNODES_H
