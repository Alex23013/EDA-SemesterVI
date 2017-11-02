#ifndef FATNODES_H
#define FATNODES_H
#include"cnode.h"
#include<QVector>

class cfatNode
{
    QVector <cNode*> versiones;
public:

    cNode* versionActual;

    cfatNode(cNode* nodo);
    int numVersiones();
    void addNodeVersion(cNode* nodo);
    void setVersion(int n);
    int getinfo();
    cNode* getChilds(bool side);
    QVector<cNode*> getVersions();
};

#endif // FATNODES_H
